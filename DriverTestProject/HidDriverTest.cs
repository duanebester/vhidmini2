using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using OmniHid;
using OmniCommon;
using System.Diagnostics;
using System.Threading;
using System.Text;

namespace DriverTestProject
{
    [TestClass]
    public class HidDriverTest
    {
        [TestMethod]
        public void TestVirtualDriver()
        {
            HIDComm OmniVirtualComm = new HIDComm(0x1A1A, "hid#sample");
            HIDComm OmniComm = new HIDComm(0x29EB, "mi_04");

            const byte keyboardMode = 0x01;
            const byte gamepadMode = 0x00;

            const byte HID_KEYB_USAGE_W = 0x1A;
            const byte HID_KEYB_USAGE_A = 0x04;
            const byte HID_KEYB_USAGE_S = 0x16;
            const byte HID_KEYB_USAGE_D = 0x07;

            //const byte HID_KEYB_LEFT_CTRL = 0x01;
            const byte HID_KEYB_LEFT_SHIFT = 0x02;
            //const byte HID_KEYB_LEFT_ALT = 0x04;
            //const byte HID_KEYB_LEFT_GUI = 0x08;
            //const byte HID_KEYB_RIGHT_CTRL = 0x10;
            //const byte HID_KEYB_RIGHT_SHIFT = 0x20;
            //const byte HID_KEYB_RIGHT_ALT = 0x40;
            //const byte HID_KEYB_RIGHT_GUI = 0x80;

            byte mode = keyboardMode;
            //byte mode = gamepadMode;

            if (OmniComm.Init() && OmniVirtualComm.Init())
            {
                Debug.WriteLine("Wooo!");

                byte[] hid_buffer = new byte[65];

                // ######## virtual_hid_buffer #########
                // Index - Explanation
                // 0 - ReportId must always be 0x01
                // 1 - mode
                // 2 - gamepad x if mode is gamepad, keyboard modifier key if keyboard mode (shift, etc)
                // 3 - gamepad y if mode is gamepad, keyboard press key if keyboard mode (w,a,s,d, etc)
                // 4 - counter that increments on every write to the device.
                byte[] virtual_hid_buffer = new byte[5];

                byte prev_timestamp = 0x00;
                byte counter = 0x00;

                byte keyboardPressShiftThreshold = (((byte)127) - ((byte)65)); // nearly half of gamepad walk speed will press shift
                //float gamepadScaleMultiplier = 1.2f; // 20% speed adjust

                try
                {
                    //OmniComm.LogAllData(); // (Do this in OmniConnect first...)
                    //Thread.Sleep(500);
                    //OmniComm.SetGamepadMode(OmniMode.ForwardBackStrafe); // Set to Coupled (Do this in OmniConnect first...)!
                    //Thread.Sleep(500);
                    OmniComm.readRaw(hid_buffer);
                    Thread.Sleep(50);

                    bool reset = false;

                    while (!reset)
                    {
                        OmniComm.readRaw(hid_buffer);

                        Debug.WriteLine(BitConverter.ToString(hid_buffer));

                        //reset = (hid_buffer[10] == prev_timestamp);

                        //if(!reset)
                        //{
                        //    prev_timestamp = hid_buffer[10];
                        //}
                        virtual_hid_buffer[0] = 0x01;
                        virtual_hid_buffer[1] = mode;
                        virtual_hid_buffer[4] = counter;

                        switch (mode)
                        {
                            case keyboardMode:

                                if (reset)
                                    goto default;
                                else
                                {
                                    if(hid_buffer[21] < 0x7e)
                                    {
                                        // w
                                        virtual_hid_buffer[2] = 0;
                                        
                                        // shift-w
                                        //if (hid_buffer[21] < keyboardPressShiftThreshold)
                                        //{
                                        //    virtual_hid_buffer[2] = HID_KEYB_LEFT_SHIFT;
                                        //}
                                        
                                        virtual_hid_buffer[3] = HID_KEYB_USAGE_W;
                                    }
                                    else if(hid_buffer[21] > 0x81)
                                    {
                                        //s
                                        virtual_hid_buffer[2] = 0;
                                        virtual_hid_buffer[3] = HID_KEYB_USAGE_S;
                                    }
                                    else if(hid_buffer[20] < 0x7e)
                                    {
                                        //a
                                        virtual_hid_buffer[2] = 0;
                                        virtual_hid_buffer[3] = HID_KEYB_USAGE_A;
                                    }
                                    else if(hid_buffer[20] > 0x80)
                                    {
                                        //d
                                        virtual_hid_buffer[2] = 0;
                                        virtual_hid_buffer[3] = HID_KEYB_USAGE_D;
                                    }
                                    else
                                    {
                                        goto default;
                                    }
                                }
                                break;

                            case gamepadMode:

                                if (reset)
                                    goto case 0x7F;
                                else
                                {
                                    virtual_hid_buffer[2] = hid_buffer[20];
                                    virtual_hid_buffer[3] = hid_buffer[21];
                                }
                                break;

                            case 0x7F:
                                virtual_hid_buffer[2] = 0x7F;
                                virtual_hid_buffer[3] = 0x7F;
                                break;

                            default:
                                virtual_hid_buffer[2] = 0x00;
                                virtual_hid_buffer[3] = 0x00;
                                break;
                        }

                        OmniVirtualComm.sendRaw(virtual_hid_buffer);
                        counter++;
                        Thread.Sleep(55);
                    }

                    Debug.WriteLine("reset?");
                }
                catch (Exception e)
                {
                    Debug.WriteLine(e.Message);
                }
            }

            /* bye bye! */
            Console.ReadLine();
        }
    }
}
