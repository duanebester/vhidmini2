#pragma once
//*****************************************************************************
//
// usbdhid.h - Definitions used by HID class devices.
//
// Copyright (c) 2008-2014 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
// 
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
// 
// This is part of revision 2.1.0.12573 of the Tiva USB Library.
//
//*****************************************************************************

#ifndef __USBDHID_H__
#define __USBDHID_H__

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
//#ifdef __cplusplus
//extern "C"
//{
//#endif

	//*****************************************************************************
	//
	//! \addtogroup hid_device_class_api
	//! @{
	//
	//*****************************************************************************

	//*****************************************************************************
	//
	// This is the size of the g_pui8HIDInterface array in bytes.
	//
	//*****************************************************************************
#define HIDINTERFACE_SIZE       (9)

	//*****************************************************************************
	//
	// This is the size of the g_pui8HIDInEndpoint array in bytes.
	//
	//*****************************************************************************
#define HIDINENDPOINT_SIZE      (7)

	//*****************************************************************************
	//
	// This is the size of the g_pui8HIDOutEndpoint array in bytes.
	//
	//*****************************************************************************
#define HIDOUTENDPOINT_SIZE     (7)

	//*****************************************************************************
	//
	// This is the size of the tHIDDescriptor in bytes.
	//
	//*****************************************************************************
#define HIDDESCRIPTOR_SIZE      (9)

	//*****************************************************************************
	//
	//! The size of the memory that should be allocated to create a configuration
	//! descriptor for a single instance of the USB HID Device.
	//! This does not include the configuration descriptor which is automatically
	//! ignored by the composite device class.
	//
	//*****************************************************************************
#define COMPOSITE_DHID_SIZE     (HIDINTERFACE_SIZE + HIDINENDPOINT_SIZE +     \
                                 HIDOUTENDPOINT_SIZE + HIDDESCRIPTOR_SIZE)

	//*****************************************************************************
	//
	// Macros used to create the static Report Descriptors.
	//
	//*****************************************************************************

	//*****************************************************************************
	//
	//! This is a macro to assist adding Usage Page entries in HID report
	//! descriptors.
	//!
	//! \param ui8Value is the Usage Page value.
	//!
	//! This macro takes a value and prepares it to be placed as a Usage Page entry
	//! into a HID report structure.  These are defined by the USB HID
	//! specification.
	//!
	//! \return Not a function.
	//
	//*****************************************************************************
#define UsagePage(ui8Value)      0x05, ((ui8Value) & 0xff)

	//*****************************************************************************
	//
	//! This is a macro to assist adding Usage Page entries in HID report
	//! descriptors when a vendor-specific value is to be used.
	//!
	//! \param ui16Value is the Usage Page value.
	//!
	//! This macro takes a value and prepares it to be placed as a Usage Page entry
	//! into a HID report structure.  These are defined by the USB HID
	//! specification.  Vendor-specific values must lie in the range 0xFF00 to
	//! 0xFFFF inclusive.
	//!
	//! \return Not a function.
	//
	//*****************************************************************************
#define UsagePageVendor(ui16Value)     0x06, ((ui16Value) & 0xFF),            \
                                       (((ui16Value) >> 8) & 0xFF)

	//*****************************************************************************
	//
	//! This is a macro to assist adding Usage entries in HID report descriptors.
	//!
	//! \param ui8Value is the Usage value.
	//!
	//! This macro takes a value and prepares it to be placed as a Usage entry into
	//! a HID report structure.  These are defined by the USB HID specification.
	//!
	//! \return Not a function.
	//
	//*****************************************************************************
#define Usage(ui8Value)          0x09, ((ui8Value) & 0xff)

	//*****************************************************************************
	//
	//! This is a macro to assist adding vendor-specific Usage entries in HID
	//! report descriptors.
	//!
	//! \param ui16Value is the vendor-specific Usage value in the range 0xFF00 to
	//! 0xFFFF.
	//!
	//! This macro takes a value and prepares it to be placed as a Usage entry into
	//! a HID report structure.  These are defined by the USB HID specification.
	//!
	//! \return Not a function.
	//
	//*****************************************************************************
#define UsageVendor(ui16Value)   0x0A, ((ui16Value) & 0xFF),            \
                                 (((ui16Value) >> 8) & 0xFF)

	//*****************************************************************************
	//
	//! This is a macro to assist adding Usage Minimum entries in HID report
	//! descriptors.
	//!
	//! \param ui8Value is the Usage Minimum value.
	//!
	//! This macro takes a value and prepares it to be placed as a Usage Minimum
	//! entry into a HID report structure.  This is the first or minimum value
	//! associated with a usage value.
	//!
	//! \return Not a function.
	//
	//*****************************************************************************
#define UsageMinimum(ui8Value)   0x19, ((ui8Value) & 0xff)

	//*****************************************************************************
	//
	//! This is a macro to assist adding Usage Maximum entries in HID report
	//! descriptors.
	//!
	//! \param ui8Value is the Usage Maximum value.
	//!
	//! This macro takes a value and prepares it to be placed as a Usage Maximum
	//! entry into a HID report structure.  This is the last or maximum value
	//! associated with a usage value.
	//!
	//! \return Not a function.
	//
	//*****************************************************************************
#define UsageMaximum(ui8Value)   0x29, ((ui8Value) & 0xff)

	//*****************************************************************************
	//
	//! This is a macro to assist adding Logical Minimum entries in HID report
	//! descriptors.
	//!
	//! \param i8Value is the Logical Minimum value.
	//!
	//! This macro takes a value and prepares it to be placed as a Logical Minimum
	//! entry into a HID report structure.  This is the actual minimum value for a
	//! range of values associated with a field.
	//!
	//! \return Not a function.
	//
	//*****************************************************************************
#define LogicalMinimum(i8Value)  0x15, ((i8Value) & 0xff)

	//*****************************************************************************
	//
	//! This is a macro to assist adding Logical Maximum entries in HID report
	//! descriptors.
	//!
	//! \param i8Value is the Logical Maximum value.
	//!
	//! This macro takes a value and prepares it to be placed as a Logical Maximum
	//! entry into a HID report structure.  This is the actual maximum value for a
	//! range of values associated with a field.
	//!
	//! \return Not a function.
	//
	//*****************************************************************************
	//#define LogicalMaximum(i8Value)  0x25, ((i8Value) & 0xff)
#define LogicalMaximum(i16Value) \
		0x26, ((i16Value) & 0xFF), \
		(((i16Value) >> 8) & 0xFF)

	//*****************************************************************************
	//
	//! This is a macro to assist adding Physical Minimum entries in HID report
	//! descriptors.
	//!
	//! \param i16Value is the Physical Minimum value.  It is a signed, 16 bit
	//! number.
	//!
	//! This macro takes a value and prepares it to be placed as a Physical Minimum
	//! entry into a HID report structure.  This is value is used in conversion of
	//! the control logical value, as returned to the host in the relevant report,
	//! to a physical measurement in the appropriate units.
	//!
	//! \return Not a function.
	//
	//*****************************************************************************
#define PhysicalMinimum(i16Value)                                           \
                                0x36, ((i16Value) & 0xFF),                    \
                                (((i16Value) >> 8) & 0xFF)

	//*****************************************************************************
	//
	//! This is a macro to assist adding Physical Maximum entries in HID report
	//! descriptors.
	//!
	//! \param i16Value is the Physical Maximum value.  It is a signed, 16 bit
	//! number.
	//!
	//! This macro takes a value and prepares it to be placed as a Physical Maximum
	//! entry into a HID report structure.  This is value is used in conversion of
	//! the control logical value, as returned to the host in the relevant report,
	//! to a physical measurement in the appropriate units.
	//!
	//! \return Not a function.
	//
	//*****************************************************************************
#define PhysicalMaximum(i16Value)                                           \
                                0x46, ((i16Value) & 0xFF),                    \
                                (((i16Value) >> 8) & 0xFF)

	//*****************************************************************************
	//
	//! This is a macro to assist adding Collection entries in HID report
	//! descriptors.
	//!
	//! \param ui8Value is the type of Collection.
	//!
	//! This macro takes a value and prepares it to be placed as a Collection
	//! entry into a HID report structure.  This is the type of values that are
	//! being grouped together, for instance input, output or features can be
	//! grouped together as a collection.
	//!
	//! \return Not a function.
	//
	//*****************************************************************************
#define Collection(ui8Value)     0xa1, ((ui8Value) & 0xff)

	//*****************************************************************************
	//
	//! This is a macro to assist adding End Collection entries in HID report
	//! descriptors.
	//!
	//! This macro can be used to place an End Collection entry into a HID report
	//! structure.  This is a tag to indicate that a collection of entries has
	//! ended in the HID report structure.  This terminates a previous Collection()
	//! entry.
	//!
	//! \return Not a function.
	//
	//*****************************************************************************
#define EndCollection           0xc0

	//*****************************************************************************
	//
	//! This is a macro to assist adding Report Count entries in HID report
	//! descriptors.
	//!
	//! \param ui8Value is the number of items in a report item.
	//!
	//! This macro takes a value and prepares it to be placed as a Report Count
	//! entry into a HID report structure.  This is number of entries of Report
	//! Size for a given item.
	//!
	//! \return Not a function.
	//
	//*****************************************************************************
#define ReportCount(ui8Value)    0x95, ((ui8Value) & 0xff)

	//*****************************************************************************
	//
	//! This is a macro to assist adding Report ID entries in HID report
	//! descriptors.
	//!
	//! \param ui8Value is the identifier prefix for the current report.
	//!
	//! This macro takes a value and prepares it to be placed as a Report ID
	//! entry into a HID report structure.  This value is used as a 1 byte prefix
	//! for the report it is contained within.
	//!
	//! \return Not a function.
	//
	//*****************************************************************************
#define ReportID(ui8Value)       0x85, ((ui8Value) & 0xff)

	//*****************************************************************************
	//
	//! This is a macro to assist adding Report Size entries in HID report
	//! descriptors.
	//!
	//! \param ui8Value is the size, in bits, of items in a report item.
	//!
	//! This macro takes a value and prepares it to be placed as a Report Size
	//! entry into a HID report structure.  This is size in bits of the entries of
	//! of a report entry.  The Report Count specifies how many entries of Report
	//! Size are in a given item.  These can be individual bits or bit fields.
	//!
	//! \return Not a function.
	//
	//*****************************************************************************
#define ReportSize(ui8Value)     0x75, ((ui8Value) & 0xff)

	//*****************************************************************************
	//
	//! This is a macro to assist adding Input entries in HID report descriptors.
	//!
	//! \param ui8Value is bit mask to specify the type of a set of input report
	//! items.  Note that if the USB_HID_INPUT_BITF flag is required, the Input2
	//! macro (which uses a 2 byte version of the Input item tag) must be used
	//! instead of this macro.
	//!
	//! This macro takes a value and prepares it to be placed as an Input entry
	//! into a HID report structure.  This specifies the type of an input item in
	//! a report structure.  These refer to a bit mask of flags that indicate the
	//! type of input for a set of items.
	//!
	//! \return Not a function.
	//
	//*****************************************************************************
#define Input(ui8Value)          0x81, ((ui8Value) & 0xff)

	//*****************************************************************************
	//
	//! This is a macro to assist adding Input entries in HID report descriptors.
	//!
	//! \param ui16Value is bit mask to specify the type of a set of input report
	//! items.  Note that this macro uses a version of the Input item tag with a
	//! two byte payload and allows any of the 8 possible data bits for the tag to
	//! be used.  If USB_HID_INPUT_BITF (bit 8) is not required, the Input macro
	//! may be used instead.
	//!
	//! This macro takes a value and prepares it to be placed as an Input entry
	//! into a HID report structure.  This specifies the type of an input item in
	//! a report structure.  These refer to a bit mask of flags that indicate the
	//! type of input for a set of items.
	//!
	//! \return Not a function.
	//
	//*****************************************************************************
#define Input2(ui16Value)       0x82, ((ui16Value) & 0xff),                   \
                                (((ui16Value) >> 8) & 0xFF)

	//*****************************************************************************
	//
	//! This is a macro to assist adding Feature entries in HID report descriptors.
	//!
	//! \param ui8Value is bit mask to specify the type of a set of feature report
	//! items.  Note that if the \b USB_HID_FEATURE_BITF flag is required, the
	//! Feature2 macro (which uses a 2 byte version of the Feature item tag) must
	//! be used instead of this macro.
	//!
	//! This macro takes a value and prepares it to be placed as a Feature entry
	//! into a HID report structure.  This specifies the type of a feature item in
	//! a report structure.  These refer to a bit mask of flags that indicate the
	//! type of feature for a set of items.
	//!
	//! \return Not a function.
	//
	//*****************************************************************************
#define Feature(ui8Value)        0xB1, ((ui8Value) & 0xff)

	//*****************************************************************************
	//
	//! This is a macro to assist adding Feature entries in HID report descriptors.
	//!
	//! \param ui16Value is bit mask to specify the type of a set of feature report
	//! items.  Note that this macro uses a version of the Feature item tag with a
	//! two byte payload and allows any of the 8 possible data bits for the tag to
	//! be used.  If \b USB_HID_FEATURE_BITF (bit 8) is not required, the Feature
	//! macro may be used instead.
	//!
	//! This macro takes a value and prepares it to be placed as a Feature entry
	//! into a HID report structure.  This specifies the type of a feature item in
	//! a report structure.  These refer to a bit mask of flags that indicate the
	//! type of feature for a set of items.
	//!
	//! \return Not a function.
	//
	//*****************************************************************************
#define Feature2(ui16Value)     0xB2, ((ui16Value) & 0xff),                   \
                                (((ui16Value) >> 8) & 0xFF)

	//*****************************************************************************
	//
	//! This is a macro to assist adding Output entries in HID report descriptors.
	//!
	//! \param ui8Value is bit mask to specify the type of a set of output report
	//! items.  Note that if the \b USB_HID_OUTPUT_BITF flag is required, the
	//! Output2 macro (which uses a 2 byte version of the Output item tag) must be
	//! used instead of this macro.
	//!
	//! This macro takes a value and prepares it to be placed as an Output entry
	//! into a HID report structure.  This specifies the type of an output item in
	//! a report structure.  These refer to a bit mask of flags that indicate the
	//! type of output for a set of items.
	//!
	//! \return Not a function.
	//
	//*****************************************************************************
#define Output(ui8Value)        0x91, ((ui8Value) & 0xff)

	//*****************************************************************************
	//
	//! This is a macro to assist adding Output entries in HID report descriptors.
	//!
	//! \param ui16Value is bit mask to specify the type of a set of output report
	//! items.  Note that this macro uses a version of the Output item tag with a
	//! two byte payload and allows any of the 8 possible data bits for the tag to
	//! be used.  If \b USB_HID_OUTPUT_BITF is not required, the Output macro
	//! may be used instead.
	//!
	//! This macro takes a value and prepares it to be placed as an Output entry
	//! into a HID report structure.  This specifies the type of an output item in
	//! a report structure.  These refer to a bit mask of flags that indicate the
	//! type of output for a set of items.
	//!
	//! \return Not a function.
	//
	//*****************************************************************************
#define Output2(ui16Value)      0x92, ((ui16Value) & 0xff),                   \
                                (((ui16Value) >> 8) & 0xFF)

	//*****************************************************************************
	//
	//! This is a macro to assist adding Unit Exponent entries in HID report
	//! descriptors.
	//!
	//! \param i8Value is the required exponent in the range [-8, 7].
	//!
	//! This macro takes a value and prepares it to be placed as a Unit Exponent
	//! entry into a HID report structure.  This is the exponent applied to
	//! PhysicalMinimum and PhysicalMaximum when scaling and converting control
	//! values to "real" units.
	//!
	//! \return Not a function.
	//
	//*****************************************************************************
#define UnitExponent(i8Value)   0x55, ((i8Value) & 0x0f)

	//*****************************************************************************
	//
	//! This is a macro to assist adding Unit entries for uncommon units in HID
	//! report descriptors.
	//!
	//! \param ui32Value is the definition of the unit required as defined in
	//! section 6.2.2.7 of the USB HID device class definition document.
	//!
	//! This macro takes a value and prepares it to be placed as a Unit entry into
	//! a HID report structure.  Note that individual macros are defined for common
	//! units and this macro is intended for use when a complex or uncommon unit
	//! is needed.  It allows entry of a 5 nibble unit definition into the report
	//! descriptor.
	//!
	//! \return Not a function.
	//
	//*****************************************************************************
#define Unit(ui32Value)         0x67, (ui32Value) & 0x0f),                    \
                                (((ui32Value) >> 8) & 0xFF),                  \
                                (((ui32Value) >> 16) & 0xFF),                 \
                                (((ui32Value) >> 24) & 0xFF)

	//*****************************************************************************
	//
	//! This macro inserts a Unit entry for centimeters into a report descriptor.
	//!
	//*****************************************************************************
#define UnitDistance_cm         0x66, 0x11, 0x00

	//*****************************************************************************
	//
	//! This macro inserts a Unit entry for inches into a report descriptor.
	//!
	//*****************************************************************************
#define UnitDistance_i          0x66, 0x13, 0x00

	//*****************************************************************************
	//
	//! This macro inserts a Unit entry for degrees into a report descriptor.
	//!
	//*****************************************************************************
#define UnitRotation_deg        0x66, 0x14, 0x00

	//*****************************************************************************
	//
	//! This macro inserts a Unit entry for radians into a report descriptor.
	//!
	//*****************************************************************************
#define UnitRotation_rad        0x66, 0x12, 0x00

	//*****************************************************************************
	//
	//! This macro inserts a Unit entry for grams into a report descriptor.
	//!
	//*****************************************************************************
#define UnitMass_g              0x66, 0x01, 0x01

	//*****************************************************************************
	//
	//! This macro inserts a Unit entry for seconds into a report descriptor.
	//!
	//*****************************************************************************
#define UnitTime_s              0x66, 0x01, 0x10

	//*****************************************************************************
	//
	//! This macro inserts a Unit entry for temperature in Kelvin into a report
	//! descriptor.
	//!
	//*****************************************************************************
#define UnitTemp_K              0x67, 0x01, 0x00, 0x01, 0x00

	//*****************************************************************************
	//
	//! This macro inserts a Unit entry for temperature in Fahrenheit into a report
	//! descriptor.
	//!
	//*****************************************************************************
#define UnitTemp_F              0x67, 0x03, 0x00, 0x01, 0x00

	//*****************************************************************************
	//
	//! This macro inserts a Unit entry for velocity in cm/s into a report
	//! descriptor.
	//!
	//*****************************************************************************
#define UnitVelocitySI          0x66, 0x11, 0xF0

	//*****************************************************************************
	//
	//! This macro inserts a Unit entry for momentum in (grams * cm)/s into a
	//! report descriptor.
	//!
	//*****************************************************************************
#define UnitMomentumSI          0x66, 0x11, 0xF1

	//*****************************************************************************
	//
	//! This macro inserts a Unit entry for acceleration in cm/s**2 into a
	//! report descriptor.
	//!
	//*****************************************************************************
#define UnitAccelerationSI      0x66, 0x11, 0xE0

	//*****************************************************************************
	//
	//! This macro inserts a Unit entry for force in (cm * grams)/s**2 into a
	//! report descriptor.
	//!
	//*****************************************************************************
#define UnitForceSI             0x66, 0x11, 0xE1

	//*****************************************************************************
	//
	//! This macro inserts a Unit entry for energy in (grams * cm^2)/(s^2) into a
	//! report descriptor.
	//!
	//*****************************************************************************
#define UnitEnergySI            0x66, 0x21, 0xE1

	//*****************************************************************************
	//
	//! This macro inserts a Unit entry for angular acceleration in degrees/(s^2)
	//! into a report descriptor.
	//!
	//*****************************************************************************
#define UnitAngAccelerationSI   0x66, 0x12, 0xE0

	//*****************************************************************************
	//
	//! This macro inserts a Unit entry for voltage into a a report descriptor.
	//!
	//*****************************************************************************
#define UnitVoltage             0x67, 0x21, 0xD1, 0xF0, 0x00

	//*****************************************************************************
	//
	//! This macro inserts a Unit entry for voltage into a a report descriptor.
	//!
	//*****************************************************************************
#define UnitCurrent_A           0x67, 0x01, 0x00, 0x10, 0x00

	//*****************************************************************************
	//
	// PRIVATE
	//
	// The first few sections of this header are private defines that are used by
	// the USB HID code and are here only to help with the application
	// allocating the correct amount of memory for the HID device code.
	//
	//*****************************************************************************
#define USBDHID_MAX_PACKET      64



	//*****************************************************************************
	//
	// HID-specific device class driver events
	//
	//*****************************************************************************

	//*****************************************************************************
	//
	//! This event indicates that the host is requesting a particular report be
	//! returned via endpoint 0, the control endpoint.  The ui32MsgValue parameter
	//! contains the requested report type in the high byte and report ID in the
	//! low byte (as passed in the wValue field of the USB request structure).
	//! The pvMsgData parameter contains a pointer which must be written with the
	//! address of the first byte of the requested report.  The callback must
	//! return the size in bytes of the report pointed to by *pvMsgData.  The
	//! memory returned in response to this event must remain unaltered until
	//! \b USBD_HID_EVENT_REPORT_SENT is sent.
	//
	//*****************************************************************************
#define USBD_HID_EVENT_GET_REPORT                                             \
                                (USBD_HID_EVENT_BASE + 0)

	//*****************************************************************************
	//
	//! This event indicates that a report previously requested via a
	//! \b USBD_HID_EVENT_GET_REPORT has been successfully transmitted to the host.
	//! The application may now free or reuse the report memory passed on the
	//! previous event.  Although this would seem to be an event that would be
	//! passed to the transmit channel callback, it is actually passed to the
	//! receive channel callback.  This ensures that all events related to the
	//! request and transmission of reports via endpoint zero can be handled in
	//! a single function.
	//
	//*****************************************************************************
#define USBD_HID_EVENT_REPORT_SENT                                            \
                                (USBD_HID_EVENT_BASE + 1)

	//*****************************************************************************
	//
	//! This event indicates that the host has sent a Set_Report request to
	//! the device and requests that the device provide a buffer into which the
	//! report can be written.  The ui32MsgValue parameter contains the received
	//! report type in the high byte and report ID in the low byte (as passed in
	//! the wValue field of the USB request structure).  The pvMsgData parameter
	//! contains the length of buffer requested.  Note that this is the actual
	//! length value cast to a "void *" type and not a pointer in this case.
	//! The callback must return a pointer to a suitable buffer (cast to the
	//! standard "uint32_t" return type for the callback).
	//
	//*****************************************************************************
#define USBD_HID_EVENT_GET_REPORT_BUFFER                                      \
                                (USBD_HID_EVENT_BASE + 2)

	//*****************************************************************************
	//
	//! This event indicates that the host has sent the device a report via
	//! endpoint 0, the control endpoint.  The ui32MsgValue field indicates the
	//! size of the report and pvMsgData points to the first byte of the report.
	//! The report buffer was previously returned in response to an
	//! earlier \b USBD_HID_EVENT_GET_REPORT_BUFFER callback.  The HID device class
	//! driver does not access the memory pointed to by pvMsgData after this
	//! callback is made so the application is free to reuse or free it at this
	//! point.
	//
	//*****************************************************************************
#define USBD_HID_EVENT_SET_REPORT                                             \
                                (USBD_HID_EVENT_BASE + 3)

	//*****************************************************************************
	//
	//! This event is sent in response to a Get_Protocol request from the host.
	//! The callback should provide the current protocol via the return code,
	//! \b USB_HID_PROTOCOL_BOOT or \b USB_HID_PROTOCOL_REPORT.
	//
	//*****************************************************************************
#define USBD_HID_EVENT_GET_PROTOCOL                                           \
                                (USBD_HID_EVENT_BASE + 4)

	//*****************************************************************************
	//
	//! This event is sent in response to a Set_Protocol request from the host.
	//! The ui32MsgData value contains the requested protocol,
	//! \b USB_HID_PROTOCOL_BOOT or \b USB_HID_PROTOCOL_REPORT.
	//
	//*****************************************************************************
#define USBD_HID_EVENT_SET_PROTOCOL                                           \
                                (USBD_HID_EVENT_BASE + 5)

	//*****************************************************************************
	//
	//! This event indicates to an application that a report idle timeout has
	//! occurred and requests a pointer to the report that must be sent back to
	//! the host.  The ui32MsgData value contains the requested report ID and
	//! pvMsgData contains a pointer that must be written with a pointer to the
	//! report data that is to be sent.  The callback must return the number of
	//! bytes in the report pointed to by *pvMsgData.
	//
	//*****************************************************************************
#define USBD_HID_EVENT_IDLE_TIMEOUT                                           \
                                (USBD_HID_EVENT_BASE + 6)


	//*****************************************************************************
	//
	// HID Interface descriptor Subclasses.
	//
	//*****************************************************************************
#define USB_HID_SCLASS_NONE     0x00
#define USB_HID_SCLASS_BOOT     0x01

	//*****************************************************************************
	//
	// USB Interface descriptor HID protocols.
	//
	//*****************************************************************************
#define USB_HID_PROTOCOL_NONE   0
#define USB_HID_PROTOCOL_KEYB   1
#define USB_HID_PROTOCOL_MOUSE  2

	//*****************************************************************************
	//
	// HID Class descriptor types.
	//
	//*****************************************************************************
#define USB_HID_DTYPE_HID       0x21
#define USB_HID_DTYPE_REPORT    0x22
#define USB_HID_DTYPE_PHYSICAL  0x23

	//*****************************************************************************
	//
	// HID USB requests.
	//
	//*****************************************************************************
#define USBREQ_GET_REPORT       0x01
#define USBREQ_GET_IDLE         0x02
#define USBREQ_GET_PROTOCOL     0x03
#define USBREQ_SET_REPORT       0x09
#define USBREQ_SET_IDLE         0x0a
#define USBREQ_SET_PROTOCOL     0x0b

	//*****************************************************************************
	//
	// GET_REPORT or SET_REPORT Definitions.
	//
	//*****************************************************************************
#define USB_HID_REPORT_IN       0x01
#define USB_HID_REPORT_OUTPUT   0x02
#define USB_HID_REPORT_FEATURE  0x03

	//*****************************************************************************
	//
	// GET_PROTOCOL or SET_PROTOCOL Definitions.
	//
	//*****************************************************************************
#define USB_HID_PROTOCOL_BOOT   0
#define USB_HID_PROTOCOL_REPORT 1

	//*****************************************************************************
	//
	// Report Values used with the Report macros.
	//
	//*****************************************************************************
#define USB_HID_GENERIC_DESKTOP 0x01
#define USB_HID_BUTTONS         0x09
#define USB_HID_X               0x30
#define USB_HID_Y               0x31
#define USB_HID_Z               0x32
#define USB_HID_RX              0x33
#define USB_HID_RY              0x34
#define USB_HID_RZ              0x35

#define USB_HID_POINTER         0x01
#define USB_HID_MOUSE           0x02
#define USB_HID_JOYSTICK        0x04
#define USB_HID_GAME_PAD        0x05
#define USB_HID_KEYBOARD        0x06

#define USB_HID_PHYSICAL        0x00
#define USB_HID_APPLICATION     0x01
#define USB_HID_LOGICAL         0x02

#define USB_HID_USAGE_POINTER   0x0109
#define USB_HID_USAGE_BUTTONS   0x0509
#define USB_HID_USAGE_LEDS      0x0508
#define USB_HID_USAGE_KEYCODES  0x0507

	//*****************************************************************************
	//
	// HID mouse button definitions as used in the first byte of the output report
	// used in the BIOS mouse protocol.
	//
	//*****************************************************************************
#define HID_MOUSE_BUTTON_1      0x01
#define HID_MOUSE_BUTTON_2      0x02
#define HID_MOUSE_BUTTON_3      0x04

	//*****************************************************************************
	//
	// HID Keyboard LED definitions as used in the first byte of the output report
	// used in the BIOS keyboard protocol.
	//
	//*****************************************************************************
#define HID_KEYB_NUM_LOCK       0x01
#define HID_KEYB_CAPS_LOCK      0x02
#define HID_KEYB_SCROLL_LOCK    0x04
#define HID_KEYB_COMPOSE        0x08
#define HID_KEYB_KANA           0x10

	//*****************************************************************************
	//
	// HID Keyboard key modifiers as provided in the first byte of the input report
	// used in the BIOS keyboard protocol.
	//
	//*****************************************************************************
#define HID_KEYB_LEFT_CTRL      0x01
#define HID_KEYB_LEFT_SHIFT     0x02
#define HID_KEYB_LEFT_ALT       0x04
#define HID_KEYB_LEFT_GUI       0x08
#define HID_KEYB_RIGHT_CTRL     0x10
#define HID_KEYB_RIGHT_SHIFT    0x20
#define HID_KEYB_RIGHT_ALT      0x40
#define HID_KEYB_RIGHT_GUI      0x80

	//*****************************************************************************
	//
	// A subset of the HID keyboard usage IDs.
	//
	//*****************************************************************************
#define HID_KEYB_USAGE_RESERVED 0x00
#define HID_KEYB_USAGE_ROLLOVER 0x01
#define HID_KEYB_USAGE_A        0x04
#define HID_KEYB_USAGE_B        0x05
#define HID_KEYB_USAGE_C        0x06
#define HID_KEYB_USAGE_D        0x07
#define HID_KEYB_USAGE_E        0x08
#define HID_KEYB_USAGE_F        0x09
#define HID_KEYB_USAGE_G        0x0A
#define HID_KEYB_USAGE_H        0x0B
#define HID_KEYB_USAGE_I        0x0C
#define HID_KEYB_USAGE_J        0x0D
#define HID_KEYB_USAGE_K        0x0E
#define HID_KEYB_USAGE_L        0x0F
#define HID_KEYB_USAGE_M        0x10
#define HID_KEYB_USAGE_N        0x11
#define HID_KEYB_USAGE_O        0x12
#define HID_KEYB_USAGE_P        0x13
#define HID_KEYB_USAGE_Q        0x14
#define HID_KEYB_USAGE_R        0x15
#define HID_KEYB_USAGE_S        0x16
#define HID_KEYB_USAGE_T        0x17
#define HID_KEYB_USAGE_U        0x18
#define HID_KEYB_USAGE_V        0x19
#define HID_KEYB_USAGE_W        0x1A
#define HID_KEYB_USAGE_X        0x1B
#define HID_KEYB_USAGE_Y        0x1C
#define HID_KEYB_USAGE_Z        0x1D
#define HID_KEYB_USAGE_1        0x1E
#define HID_KEYB_USAGE_2        0x1F
#define HID_KEYB_USAGE_3        0x20
#define HID_KEYB_USAGE_4        0x21
#define HID_KEYB_USAGE_5        0x22
#define HID_KEYB_USAGE_6        0x23
#define HID_KEYB_USAGE_7        0x24
#define HID_KEYB_USAGE_8        0x25
#define HID_KEYB_USAGE_9        0x26
#define HID_KEYB_USAGE_0        0x27
#define HID_KEYB_USAGE_ENTER    0x28
#define HID_KEYB_USAGE_ESCAPE   0x29
#define HID_KEYB_USAGE_BACKSPACE \
                                0x2A
#define HID_KEYB_USAGE_TAB      0x2B
#define HID_KEYB_USAGE_SPACE    0x2C
#define HID_KEYB_USAGE_MINUS    0x2D
#define HID_KEYB_USAGE_EQUAL    0x2E
#define HID_KEYB_USAGE_LBRACKET 0x2F
#define HID_KEYB_USAGE_RBRACKET 0x30
#define HID_KEYB_USAGE_BSLASH   0x31
#define HID_KEYB_USAGE_SEMICOLON \
                                0x33
#define HID_KEYB_USAGE_FQUOTE   0x34
#define HID_KEYB_USAGE_BQUOTE   0x35
#define HID_KEYB_USAGE_COMMA    0x36
#define HID_KEYB_USAGE_PERIOD   0x37
#define HID_KEYB_USAGE_FSLASH   0x38
#define HID_KEYB_USAGE_CAPSLOCK 0x39
#define HID_KEYB_USAGE_F1       0x3A
#define HID_KEYB_USAGE_F2       0x3B
#define HID_KEYB_USAGE_F3       0x3C
#define HID_KEYB_USAGE_F4       0x3D
#define HID_KEYB_USAGE_F5       0x3E
#define HID_KEYB_USAGE_F6       0x3F
#define HID_KEYB_USAGE_F7       0x40
#define HID_KEYB_USAGE_F8       0x41
#define HID_KEYB_USAGE_F9       0x42
#define HID_KEYB_USAGE_F10      0x43
#define HID_KEYB_USAGE_F11      0x44
#define HID_KEYB_USAGE_F12      0x45
#define HID_KEYB_USAGE_SCROLLOCK   \
                                0x47
#define HID_KEYB_USAGE_PAGE_UP  0x4B
#define HID_KEYB_USAGE_PAGE_DOWN   \
                                0x4E
#define HID_KEYB_USAGE_RIGHT_ARROW \
                                0x4F
#define HID_KEYB_USAGE_LEFT_ARROW \
                                0x50
#define HID_KEYB_USAGE_DOWN_ARROW \
                                0x51
#define HID_KEYB_USAGE_UP_ARROW 0x52
#define HID_KEYB_USAGE_NUMLOCK  0x53
#define HID_KEYB_USAGE_KEYPAD_SLASH \
                                0x54
#define HID_KEYB_USAGE_KEYPAD_STAR \
                                0x55
#define HID_KEYB_USAGE_KEYPAD_MINUS \
                                0x56
#define HID_KEYB_USAGE_KEYPAD_PLUS \
                                0x57
#define HID_KEYB_USAGE_KEPAD_ENTER \
                                0x58
#define HID_KEYB_USAGE_KEYPAD_1 0x59
#define HID_KEYB_USAGE_KEYPAD_2 0x5A
#define HID_KEYB_USAGE_KEYPAD_3 0x5B
#define HID_KEYB_USAGE_KEYPAD_4 0x5C
#define HID_KEYB_USAGE_KEYPAD_5 0x5D
#define HID_KEYB_USAGE_KEYPAD_6 0x5E
#define HID_KEYB_USAGE_KEYPAD_7 0x5F
#define HID_KEYB_USAGE_KEYPAD_8 0x60
#define HID_KEYB_USAGE_KEYPAD_9 0x61
#define HID_KEYB_USAGE_KEYPAD_0 0x62
#define HID_KEYB_USAGE_KEPAD_PERIOD \
                                0x63

	//*****************************************************************************
	//
	// HID descriptor country codes (most of these are described as "countries" in
	// the HID specification even though they are really languages).
	//
	//*****************************************************************************
#define USB_HID_COUNTRY_NONE    0x00
#define USB_HID_COUNTRY_ARABIC  0x01
#define USB_HID_COUNTRY_BELGIAN 0x02
#define USB_HID_COUNTRY_CANADA_BI \
                                0x03
#define USB_HID_COUNTRY_CANADA_FR \
                                0x04
#define USB_HID_COUNTRY_CZECH_REPUBLIC \
                                0x05
#define USB_HID_COUNTRY_DANISH  0x06
#define USB_HID_COUNTRY_FINNISH 0x07
#define USB_HID_COUNTRY_FRENCH  0x08
#define USB_HID_COUNTRY_GERMAN  0x09
#define USB_HID_COUNTRY_GREEK   0x0A
#define USB_HID_COUNTRY_HEBREW  0x0B
#define USB_HID_COUNTRY_HUNGARY 0x0C
#define USB_HID_COUNTRY_INTERNATIONAL_ISO \
                                0x0D
#define USB_HID_COUNTRY_ITALIAN 0x0E
#define USB_HID_COUNTRY_JAPAN_KATAKANA \
                                0x0F
#define USB_HID_COUNTRY_KOREAN  0x10
#define USB_HID_COUNTRY_LATIN_AMERICAN \
                                0x11
#define USB_HID_COUNTRY_NETHERLANDS \
                                0x12
#define USB_HID_COUNTRY_NORWEGIAN \
                                0x13
#define USB_HID_COUNTRY_PERSIAN 0x14
#define USB_HID_COUNTRY_POLAND  0x15
#define USB_HID_COUNTRY_PORTUGUESE \
                                0x16
#define USB_HID_COUNTRY_RUSSIA  0x17
#define USB_HID_COUNTRY_SLOVAKIA \
                                0x18
#define USB_HID_COUNTRY_SPANISH 0x19
#define USB_HID_COUNTRY_SWEDISH 0x1A
#define USB_HID_COUNTRY_SWISS_FRENCH \
                                0x1B
#define USB_HID_COUNTRY_SWISS_GERMAN \
                                0x1C
#define USB_HID_COUNTRY_SWITZERLAND \
                                0x1D
#define USB_HID_COUNTRY_TAIWAN  0x1E
#define USB_HID_COUNTRY_TURKISH_Q \
                                0x1F
#define USB_HID_COUNTRY_UK      0x20
#define USB_HID_COUNTRY_US      0x21
#define USB_HID_COUNTRY_YUGOSLAVIA \
                                0x22
#define USB_HID_COUNTRY_TURKISH_F \
                                0x23

	//*****************************************************************************
	//
	// Data flags used in Input item tags within report descriptors.
	//
	//*****************************************************************************
#define USB_HID_INPUT_DATA      0x0000
#define USB_HID_INPUT_CONSTANT  0x0001
#define USB_HID_INPUT_ARRAY     0x0000
#define USB_HID_INPUT_VARIABLE  0x0002
#define USB_HID_INPUT_ABS       0x0000
#define USB_HID_INPUT_RELATIVE  0x0004
#define USB_HID_INPUT_NOWRAP    0x0000
#define USB_HID_INPUT_WRAP      0x0008
#define USB_HID_INPUT_LINEAR    0x0000
#define USB_HID_INPUT_NONLINEAR 0x0010
#define USB_HID_INPUT_PREFER    0x0000
#define USB_HID_INPUT_NONPREFER 0x0020
#define USB_HID_INPUT_NONULL    0x0000
#define USB_HID_INPUT_NULL      0x0040
#define USB_HID_INPUT_BITF      0x0100
#define USB_HID_INPUT_BYTES     0x0000

	//*****************************************************************************
	//
	// Data flags used in Feature item tags within report descriptors.
	//
	//*****************************************************************************
#define USB_HID_FEATURE_DATA    0x0000
#define USB_HID_FEATURE_CONSTANT \
                                0x0001
#define USB_HID_FEATURE_ARRAY   0x0000
#define USB_HID_FEATURE_VARIABLE \
                                0x0002
#define USB_HID_FEATURE_ABS     0x0000
#define USB_HID_FEATURE_RELATIVE \
                                0x0004
#define USB_HID_FEATURE_NOWRAP  0x0000
#define USB_HID_FEATURE_WRAP    0x0008
#define USB_HID_FEATURE_LINEAR  0x0000
#define USB_HID_FEATURE_NONLINEAR \
                                0x0010
#define USB_HID_FEATURE_PREFER  0x0000
#define USB_HID_FEATURE_NONPREFER \
                                0x0020
#define USB_HID_FEATURE_NONULL  0x0000
#define USB_HID_FEATURE_NULL    0x0040
#define USB_HID_FEATURE_BITF    0x0100
#define USB_HID_FEATURE_BYTES   0x0000

	//*****************************************************************************
	//
	// Data flags used in Output item tags within report descriptors.
	//
	//*****************************************************************************
#define USB_HID_OUTPUT_DATA     0x0000
#define USB_HID_OUTPUT_CONSTANT 0x0001
#define USB_HID_OUTPUT_ARRAY    0x0000
#define USB_HID_OUTPUT_VARIABLE 0x0002
#define USB_HID_OUTPUT_ABS      0x0000
#define USB_HID_OUTPUT_RELATIVE 0x0004
#define USB_HID_OUTPUT_NOWRAP   0x0000
#define USB_HID_OUTPUT_WRAP     0x0008
#define USB_HID_OUTPUT_LINEAR   0x0000
#define USB_HID_OUTPUT_NONLINEAR \
                                0x0010
#define USB_HID_OUTPUT_PREFER   0x0000
#define USB_HID_OUTPUT_NONPREFER \
                                0x0020
#define USB_HID_OUTPUT_NONULL   0x0000
#define USB_HID_OUTPUT_NULL     0x0040
#define USB_HID_OUTPUT_BITF     0x0100
#define USB_HID_OUTPUT_BYTES    0x0000

	//*****************************************************************************
	//
	// Physical descriptor bias values.
	//
	//*****************************************************************************
#define USB_HID_BIAS_NOT_APPLICABLE \
                                0x00
#define USB_HID_BIAS_RIGHT_HAND 0x01
#define USB_HID_BIAS_LEFT_HAND  0x02
#define USB_HID_BIAS_BOTH_HANDS 0x03
#define USB_HID_BIAS_EITHER_HAND \
                                0x04

	//*****************************************************************************
	//
	// Physical descriptor designator values.
	//
	//*****************************************************************************
#define USB_HID_DESIGNATOR_NONE 0x00
#define USB_HID_DESIGNATOR_HAND 0x01
#define USB_HID_DESIGNATOR_EYEBALL \
                                0x02
#define USB_HID_DESIGNATOR_EYEBROW \
                                0x03
#define USB_HID_DESIGNATOR_EYELID \
                                0x04
#define USB_HID_DESIGNATOR_EAR  0x05
#define USB_HID_DESIGNATOR_NOSE 0x06
#define USB_HID_DESIGNATOR_MOUTH \
                                0x07
#define USB_HID_DESIGNATOR_UPPER_LIP \
                                0x08
#define USB_HID_DESIGNATOR_LOWER_LIP \
                                0x09
#define USB_HID_DESIGNATOR_JAW  0x0A
#define USB_HID_DESIGNATOR_NECK 0x0B
#define USB_HID_DESIGNATOR_UPPER_ARM \
                                0x0C
#define USB_HID_DESIGNATOR_ELBOW \
                                0x0D
#define USB_HID_DESIGNATOR_FOREARM \
                                0x0E
#define USB_HID_DESIGNATOR_WRIST \
                                0x0F
#define USB_HID_DESIGNATOR_PALM 0x10
#define USB_HID_DESIGNATOR_THUMB \
                                0x11
#define USB_HID_DESIGNATOR_INDEX_FINGER \
                                0x12
#define USB_HID_DESIGNATOR_MIDDLE_FINGER \
                                0x13
#define USB_HID_DESIGNATOR_RING_FINGER \
                                0x14
#define USB_HID_DESIGNATOR_LITTLE_FINGER \
                                0x15
#define USB_HID_DESIGNATOR_HEAD 0x16
#define USB_HID_DESIGNATOR_SHOULDER \
                                0x17
#define USB_HID_DESIGNATOR_HIP  0x18
#define USB_HID_DESIGNATOR_WAIST \
                                0x19
#define USB_HID_DESIGNATOR_THIGH \
                                0x1A
#define USB_HID_DESIGNATOR_KNEE 0x1B
#define USB_HID_DESIGNATOR_CALF 0x1C
#define USB_HID_DESIGNATOR_ANKLE \
                                0x1D
#define USB_HID_DESIGNATOR_FOOT 0x1E
#define USB_HID_DESIGNATOR_HEEL 0x1F
#define USB_HID_DESIGNATOR_BALL_OF_FOOT \
                                0x20
#define USB_HID_DESIGNATOR_BIG_TOE \
                                0x21
#define USB_HID_DESIGNATOR_SECOND_TOE \
                                0x22
#define USB_HID_DESIGNATOR_THIRD_TOE \
                                0x23
#define USB_HID_DESIGNATOR_FOURTH_TOE \
                                0x24
#define USB_HID_DESIGNATOR_LITTLE_TOE \
                                0x25
#define USB_HID_DESIGNATOR_BROW 0x26
#define USB_HID_DESIGNATOR_CHEEK \
                                0x27

	//*****************************************************************************
	//
	// Physical descriptor qualifier values.
	//
	//*****************************************************************************
#define USB_HID_QUALIFIER_NOT_APPLICABLE    \
                                (0x00 << 5)
#define USB_HID_QUALIFIER_RIGHT (0x01 << 5)
#define USB_HID_QUALIFIER_LEFT  (0x02 << 5)
#define USB_HID_QUALIFIER_BOTH  (0x03 << 5)
#define USB_HID_QUALIFIER_EITHER \
                                (0x04 << 5)
#define USB_HID_QUALIFIER_CENTER \
                                (0x05 << 5)

	//*****************************************************************************
	//
	// This is the maximum value for a usage code.
	//
	//*****************************************************************************
#define USBH_HID_MAX_USAGE      256
#define USBH_HID_CAPS_ARRAY_SZ  (USBH_HID_MAX_USAGE/sizeof(uint32_t))





	//*****************************************************************************
	//
	// Mark the end of the C bindings section for C++ compilers.
	//
	//*****************************************************************************
//#ifdef __cplusplus
//}
//#endif

#endif // __USBDHID_H__


