/* soapStub.h
   Generated by gSOAP 2.8.91 for calc.h

gSOAP XML Web services tools
Copyright (C) 2000-2018, Robert van Engelen, Genivia Inc. All Rights Reserved.
The soapcpp2 tool and its generated software are released under the GPL.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial use license is available from Genivia Inc., contact@genivia.com
--------------------------------------------------------------------------------
*/

#include <vector>
#define SOAP_NAMESPACE_OF_ns2	"urn:calc"

#ifndef soapStub_H
#define soapStub_H
#include "stdsoap2.h"
#if GSOAP_VERSION != 20891
# error "GSOAP VERSION 20891 MISMATCH IN GENERATED CODE VERSUS LIBRARY CODE: PLEASE REINSTALL PACKAGE"
#endif


/******************************************************************************\
 *                                                                            *
 * Types with Custom Serializers                                              *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Classes, Structs and Unions                                                *
 *                                                                            *
\******************************************************************************/

struct ns2__addResponse;	/* calc.h:1 */
struct ns2__add;	/* calc.h:1 */
struct ns2__subResponse;	/* calc.h:1 */
struct ns2__sub;	/* calc.h:1 */
struct ns2__mulResponse;	/* calc.h:1 */
struct ns2__mul;	/* calc.h:1 */
struct ns2__divResponse;	/* calc.h:1 */
struct ns2__div;	/* calc.h:1 */
struct ns2__powResponse;	/* calc.h:1 */
struct ns2__pow;	/* calc.h:1 */

/* calc.h:1 */
#ifndef SOAP_TYPE_ns2__addResponse
#define SOAP_TYPE_ns2__addResponse (11)
/* complex XML schema type 'ns2:addResponse': */
struct SOAP_CMAC ns2__addResponse {
      public:
        /** Required element 'result' of XML schema type 'xsd:double' */
        double result;
      public:
        /** Return unique type id SOAP_TYPE_ns2__addResponse */
        long soap_type() const { return SOAP_TYPE_ns2__addResponse; }
        /** Constructor with member initializations */
        ns2__addResponse() : result() { }
        /** Friend allocator */
        friend SOAP_FMAC1 ns2__addResponse * SOAP_FMAC2 soap_instantiate_ns2__addResponse(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* calc.h:1 */
#ifndef SOAP_TYPE_ns2__add
#define SOAP_TYPE_ns2__add (12)
/* complex XML schema type 'ns2:add': */
struct SOAP_CMAC ns2__add {
      public:
        /** Required element 'a' of XML schema type 'xsd:double' */
        double a;
        /** Required element 'b' of XML schema type 'xsd:double' */
        double b;
      public:
        /** Return unique type id SOAP_TYPE_ns2__add */
        long soap_type() const { return SOAP_TYPE_ns2__add; }
        /** Constructor with member initializations */
        ns2__add() : a(), b() { }
        /** Friend allocator */
        friend SOAP_FMAC1 ns2__add * SOAP_FMAC2 soap_instantiate_ns2__add(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* calc.h:1 */
#ifndef SOAP_TYPE_ns2__subResponse
#define SOAP_TYPE_ns2__subResponse (14)
/* complex XML schema type 'ns2:subResponse': */
struct SOAP_CMAC ns2__subResponse {
      public:
        /** Required element 'result' of XML schema type 'xsd:double' */
        double result;
      public:
        /** Return unique type id SOAP_TYPE_ns2__subResponse */
        long soap_type() const { return SOAP_TYPE_ns2__subResponse; }
        /** Constructor with member initializations */
        ns2__subResponse() : result() { }
        /** Friend allocator */
        friend SOAP_FMAC1 ns2__subResponse * SOAP_FMAC2 soap_instantiate_ns2__subResponse(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* calc.h:1 */
#ifndef SOAP_TYPE_ns2__sub
#define SOAP_TYPE_ns2__sub (15)
/* complex XML schema type 'ns2:sub': */
struct SOAP_CMAC ns2__sub {
      public:
        /** Required element 'a' of XML schema type 'xsd:double' */
        double a;
        /** Required element 'b' of XML schema type 'xsd:double' */
        double b;
      public:
        /** Return unique type id SOAP_TYPE_ns2__sub */
        long soap_type() const { return SOAP_TYPE_ns2__sub; }
        /** Constructor with member initializations */
        ns2__sub() : a(), b() { }
        /** Friend allocator */
        friend SOAP_FMAC1 ns2__sub * SOAP_FMAC2 soap_instantiate_ns2__sub(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* calc.h:1 */
#ifndef SOAP_TYPE_ns2__mulResponse
#define SOAP_TYPE_ns2__mulResponse (17)
/* complex XML schema type 'ns2:mulResponse': */
struct SOAP_CMAC ns2__mulResponse {
      public:
        /** Required element 'result' of XML schema type 'xsd:double' */
        double result;
      public:
        /** Return unique type id SOAP_TYPE_ns2__mulResponse */
        long soap_type() const { return SOAP_TYPE_ns2__mulResponse; }
        /** Constructor with member initializations */
        ns2__mulResponse() : result() { }
        /** Friend allocator */
        friend SOAP_FMAC1 ns2__mulResponse * SOAP_FMAC2 soap_instantiate_ns2__mulResponse(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* calc.h:1 */
#ifndef SOAP_TYPE_ns2__mul
#define SOAP_TYPE_ns2__mul (18)
/* complex XML schema type 'ns2:mul': */
struct SOAP_CMAC ns2__mul {
      public:
        /** Required element 'a' of XML schema type 'xsd:double' */
        double a;
        /** Required element 'b' of XML schema type 'xsd:double' */
        double b;
      public:
        /** Return unique type id SOAP_TYPE_ns2__mul */
        long soap_type() const { return SOAP_TYPE_ns2__mul; }
        /** Constructor with member initializations */
        ns2__mul() : a(), b() { }
        /** Friend allocator */
        friend SOAP_FMAC1 ns2__mul * SOAP_FMAC2 soap_instantiate_ns2__mul(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* calc.h:1 */
#ifndef SOAP_TYPE_ns2__divResponse
#define SOAP_TYPE_ns2__divResponse (20)
/* complex XML schema type 'ns2:divResponse': */
struct SOAP_CMAC ns2__divResponse {
      public:
        /** Required element 'result' of XML schema type 'xsd:double' */
        double result;
      public:
        /** Return unique type id SOAP_TYPE_ns2__divResponse */
        long soap_type() const { return SOAP_TYPE_ns2__divResponse; }
        /** Constructor with member initializations */
        ns2__divResponse() : result() { }
        /** Friend allocator */
        friend SOAP_FMAC1 ns2__divResponse * SOAP_FMAC2 soap_instantiate_ns2__divResponse(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* calc.h:1 */
#ifndef SOAP_TYPE_ns2__div
#define SOAP_TYPE_ns2__div (21)
/* complex XML schema type 'ns2:div': */
struct SOAP_CMAC ns2__div {
      public:
        /** Required element 'a' of XML schema type 'xsd:double' */
        double a;
        /** Required element 'b' of XML schema type 'xsd:double' */
        double b;
      public:
        /** Return unique type id SOAP_TYPE_ns2__div */
        long soap_type() const { return SOAP_TYPE_ns2__div; }
        /** Constructor with member initializations */
        ns2__div() : a(), b() { }
        /** Friend allocator */
        friend SOAP_FMAC1 ns2__div * SOAP_FMAC2 soap_instantiate_ns2__div(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* calc.h:1 */
#ifndef SOAP_TYPE_ns2__powResponse
#define SOAP_TYPE_ns2__powResponse (23)
/* complex XML schema type 'ns2:powResponse': */
struct SOAP_CMAC ns2__powResponse {
      public:
        /** Required element 'result' of XML schema type 'xsd:double' */
        double result;
      public:
        /** Return unique type id SOAP_TYPE_ns2__powResponse */
        long soap_type() const { return SOAP_TYPE_ns2__powResponse; }
        /** Constructor with member initializations */
        ns2__powResponse() : result() { }
        /** Friend allocator */
        friend SOAP_FMAC1 ns2__powResponse * SOAP_FMAC2 soap_instantiate_ns2__powResponse(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* calc.h:1 */
#ifndef SOAP_TYPE_ns2__pow
#define SOAP_TYPE_ns2__pow (24)
/* complex XML schema type 'ns2:pow': */
struct SOAP_CMAC ns2__pow {
      public:
        /** Required element 'a' of XML schema type 'xsd:double' */
        double a;
        /** Required element 'b' of XML schema type 'xsd:double' */
        double b;
      public:
        /** Return unique type id SOAP_TYPE_ns2__pow */
        long soap_type() const { return SOAP_TYPE_ns2__pow; }
        /** Constructor with member initializations */
        ns2__pow() : a(), b() { }
        /** Friend allocator */
        friend SOAP_FMAC1 ns2__pow * SOAP_FMAC2 soap_instantiate_ns2__pow(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* calc.h:1 */
#ifndef WITH_NOGLOBAL
#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (25)
/* SOAP_ENV__Header: */
struct SOAP_CMAC SOAP_ENV__Header {
      public:
        /** Return unique type id SOAP_TYPE_SOAP_ENV__Header */
        long soap_type() const { return SOAP_TYPE_SOAP_ENV__Header; }
        /** Constructor with member initializations */
        SOAP_ENV__Header() { }
        /** Friend allocator */
        friend SOAP_FMAC1 SOAP_ENV__Header * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Header(struct soap*, int, const char*, const char*, size_t*);
};
#endif
#endif

/* calc.h:1 */
#ifndef WITH_NOGLOBAL
#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (26)
/* Type SOAP_ENV__Code is a recursive data type, (in)directly referencing itself through its (base or derived class) members */
/* SOAP_ENV__Code: */
struct SOAP_CMAC SOAP_ENV__Code {
      public:
        /** Optional element 'SOAP-ENV:Value' of XML schema type 'xsd:QName' */
        char *SOAP_ENV__Value;
        /** Optional element 'SOAP-ENV:Subcode' of XML schema type 'SOAP-ENV:Code' */
        struct SOAP_ENV__Code *SOAP_ENV__Subcode;
      public:
        /** Return unique type id SOAP_TYPE_SOAP_ENV__Code */
        long soap_type() const { return SOAP_TYPE_SOAP_ENV__Code; }
        /** Constructor with member initializations */
        SOAP_ENV__Code() : SOAP_ENV__Value(), SOAP_ENV__Subcode() { }
        /** Friend allocator */
        friend SOAP_FMAC1 SOAP_ENV__Code * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Code(struct soap*, int, const char*, const char*, size_t*);
};
#endif
#endif

/* calc.h:1 */
#ifndef WITH_NOGLOBAL
#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (28)
/* SOAP_ENV__Detail: */
struct SOAP_CMAC SOAP_ENV__Detail {
      public:
        char *__any;
        /** Any type of element 'fault' assigned to fault with its SOAP_TYPE_<typename> assigned to __type */
        /** Do not create a cyclic data structure through this member unless SOAP encoding or SOAP_XML_GRAPH are used for id-ref serialization */
        int __type;
        void *fault;
      public:
        /** Return unique type id SOAP_TYPE_SOAP_ENV__Detail */
        long soap_type() const { return SOAP_TYPE_SOAP_ENV__Detail; }
        /** Constructor with member initializations */
        SOAP_ENV__Detail() : __any(), __type(), fault() { }
        /** Friend allocator */
        friend SOAP_FMAC1 SOAP_ENV__Detail * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Detail(struct soap*, int, const char*, const char*, size_t*);
};
#endif
#endif

/* calc.h:1 */
#ifndef WITH_NOGLOBAL
#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (31)
/* SOAP_ENV__Reason: */
struct SOAP_CMAC SOAP_ENV__Reason {
      public:
        /** Optional element 'SOAP-ENV:Text' of XML schema type 'xsd:string' */
        char *SOAP_ENV__Text;
      public:
        /** Return unique type id SOAP_TYPE_SOAP_ENV__Reason */
        long soap_type() const { return SOAP_TYPE_SOAP_ENV__Reason; }
        /** Constructor with member initializations */
        SOAP_ENV__Reason() : SOAP_ENV__Text() { }
        /** Friend allocator */
        friend SOAP_FMAC1 SOAP_ENV__Reason * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Reason(struct soap*, int, const char*, const char*, size_t*);
};
#endif
#endif

/* calc.h:1 */
#ifndef WITH_NOGLOBAL
#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (32)
/* SOAP_ENV__Fault: */
struct SOAP_CMAC SOAP_ENV__Fault {
      public:
        /** Optional element 'faultcode' of XML schema type 'xsd:QName' */
        char *faultcode;
        /** Optional element 'faultstring' of XML schema type 'xsd:string' */
        char *faultstring;
        /** Optional element 'faultactor' of XML schema type 'xsd:string' */
        char *faultactor;
        /** Optional element 'detail' of XML schema type 'SOAP-ENV:Detail' */
        struct SOAP_ENV__Detail *detail;
        /** Optional element 'SOAP-ENV:Code' of XML schema type 'SOAP-ENV:Code' */
        struct SOAP_ENV__Code *SOAP_ENV__Code;
        /** Optional element 'SOAP-ENV:Reason' of XML schema type 'SOAP-ENV:Reason' */
        struct SOAP_ENV__Reason *SOAP_ENV__Reason;
        /** Optional element 'SOAP-ENV:Node' of XML schema type 'xsd:string' */
        char *SOAP_ENV__Node;
        /** Optional element 'SOAP-ENV:Role' of XML schema type 'xsd:string' */
        char *SOAP_ENV__Role;
        /** Optional element 'SOAP-ENV:Detail' of XML schema type 'SOAP-ENV:Detail' */
        struct SOAP_ENV__Detail *SOAP_ENV__Detail;
      public:
        /** Return unique type id SOAP_TYPE_SOAP_ENV__Fault */
        long soap_type() const { return SOAP_TYPE_SOAP_ENV__Fault; }
        /** Constructor with member initializations */
        SOAP_ENV__Fault() : faultcode(), faultstring(), faultactor(), detail(), SOAP_ENV__Code(), SOAP_ENV__Reason(), SOAP_ENV__Node(), SOAP_ENV__Role(), SOAP_ENV__Detail() { }
        /** Friend allocator */
        friend SOAP_FMAC1 SOAP_ENV__Fault * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Fault(struct soap*, int, const char*, const char*, size_t*);
};
#endif
#endif

/******************************************************************************\
 *                                                                            *
 * Typedefs                                                                   *
 *                                                                            *
\******************************************************************************/


/* (built-in):0 */
#ifndef SOAP_TYPE__XML
#define SOAP_TYPE__XML (5)
typedef char *_XML;
#endif

/* (built-in):0 */
#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (6)
typedef char *_QName;
#endif

/******************************************************************************\
 *                                                                            *
 * Serializable Types                                                         *
 *                                                                            *
\******************************************************************************/


/* char has binding name 'byte' for type 'xsd:byte' */
#ifndef SOAP_TYPE_byte
#define SOAP_TYPE_byte (3)
#endif

/* int has binding name 'int' for type 'xsd:int' */
#ifndef SOAP_TYPE_int
#define SOAP_TYPE_int (1)
#endif

/* double has binding name 'double' for type 'xsd:double' */
#ifndef SOAP_TYPE_double
#define SOAP_TYPE_double (8)
#endif

/* struct SOAP_ENV__Fault has binding name 'SOAP_ENV__Fault' for type '' */
#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (32)
#endif

/* struct SOAP_ENV__Reason has binding name 'SOAP_ENV__Reason' for type '' */
#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (31)
#endif

/* struct SOAP_ENV__Detail has binding name 'SOAP_ENV__Detail' for type '' */
#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (28)
#endif

/* struct SOAP_ENV__Code has binding name 'SOAP_ENV__Code' for type '' */
#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (26)
#endif

/* struct SOAP_ENV__Header has binding name 'SOAP_ENV__Header' for type '' */
#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (25)
#endif

/* struct ns2__pow has binding name 'ns2__pow' for type 'ns2:pow' */
#ifndef SOAP_TYPE_ns2__pow
#define SOAP_TYPE_ns2__pow (24)
#endif

/* struct ns2__powResponse has binding name 'ns2__powResponse' for type 'ns2:powResponse' */
#ifndef SOAP_TYPE_ns2__powResponse
#define SOAP_TYPE_ns2__powResponse (23)
#endif

/* struct ns2__div has binding name 'ns2__div' for type 'ns2:div' */
#ifndef SOAP_TYPE_ns2__div
#define SOAP_TYPE_ns2__div (21)
#endif

/* struct ns2__divResponse has binding name 'ns2__divResponse' for type 'ns2:divResponse' */
#ifndef SOAP_TYPE_ns2__divResponse
#define SOAP_TYPE_ns2__divResponse (20)
#endif

/* struct ns2__mul has binding name 'ns2__mul' for type 'ns2:mul' */
#ifndef SOAP_TYPE_ns2__mul
#define SOAP_TYPE_ns2__mul (18)
#endif

/* struct ns2__mulResponse has binding name 'ns2__mulResponse' for type 'ns2:mulResponse' */
#ifndef SOAP_TYPE_ns2__mulResponse
#define SOAP_TYPE_ns2__mulResponse (17)
#endif

/* struct ns2__sub has binding name 'ns2__sub' for type 'ns2:sub' */
#ifndef SOAP_TYPE_ns2__sub
#define SOAP_TYPE_ns2__sub (15)
#endif

/* struct ns2__subResponse has binding name 'ns2__subResponse' for type 'ns2:subResponse' */
#ifndef SOAP_TYPE_ns2__subResponse
#define SOAP_TYPE_ns2__subResponse (14)
#endif

/* struct ns2__add has binding name 'ns2__add' for type 'ns2:add' */
#ifndef SOAP_TYPE_ns2__add
#define SOAP_TYPE_ns2__add (12)
#endif

/* struct ns2__addResponse has binding name 'ns2__addResponse' for type 'ns2:addResponse' */
#ifndef SOAP_TYPE_ns2__addResponse
#define SOAP_TYPE_ns2__addResponse (11)
#endif

/* struct SOAP_ENV__Reason * has binding name 'PointerToSOAP_ENV__Reason' for type '' */
#ifndef SOAP_TYPE_PointerToSOAP_ENV__Reason
#define SOAP_TYPE_PointerToSOAP_ENV__Reason (34)
#endif

/* struct SOAP_ENV__Detail * has binding name 'PointerToSOAP_ENV__Detail' for type '' */
#ifndef SOAP_TYPE_PointerToSOAP_ENV__Detail
#define SOAP_TYPE_PointerToSOAP_ENV__Detail (33)
#endif

/* struct SOAP_ENV__Code * has binding name 'PointerToSOAP_ENV__Code' for type '' */
#ifndef SOAP_TYPE_PointerToSOAP_ENV__Code
#define SOAP_TYPE_PointerToSOAP_ENV__Code (27)
#endif

/* _QName has binding name '_QName' for type 'xsd:QName' */
#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (6)
#endif

/* _XML has binding name '_XML' for type '' */
#ifndef SOAP_TYPE__XML
#define SOAP_TYPE__XML (5)
#endif

/* char * has binding name 'string' for type 'xsd:string' */
#ifndef SOAP_TYPE_string
#define SOAP_TYPE_string (4)
#endif

/******************************************************************************\
 *                                                                            *
 * Externals                                                                  *
 *                                                                            *
\******************************************************************************/


#endif

/* End of soapStub.h */
