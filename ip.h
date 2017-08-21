#ifndef FLTR_IP_H
#define FLTR_IP_H

struct IPv4_HEADER {
	/*
	UCHAR Version : 4;
	UCHAR IHL : 4;
	UCHAR DSCP : 6;
	UCHAR ECN : 2;
	*/
	USHORT VIDE;
	USHORT TotalLength;
	USHORT Identification;
	/*
	USHORT Flags:3;
	USHORT FragmentOffset : 13;
	*/
	USHORT FFO;
	UCHAR TTL;
	UCHAR Protocol;
	USHORT HeaderChecksum;
	UCHAR SourceAddress[4];
	UCHAR DestinationAddress[4];
};

struct IPv6_HEADER {
	/*
	____________________________________________
	|  4 bits		8 bits			20 bits		|
	| Version | Traffic Class | Flow Label		|
	|___________________________________________|
	*/
	ULONG Version:4;				// Version (4 bits) 
	ULONG TrafficClass : 8;			// Traffic Class (8 bits)
	ULONG FlowLabel : 20;			// Flow Label (20 bits) 
	/*
	____________________________________________
	|	16 bits			8 bits			8 bits	|
	| Payload Length | NextHeader |	 Hop Limit	|
	|___________________________________________|
	*/
	ULONG PayloadLength : 16;		// Payload Length (16 bits) 
	ULONG NextHeader : 8;			// Next Header (8 bits)
	ULONG HopLimit : 8;				// Hop Limit (8 bits) 
	/*
	____________________________________________
	|	16 bits							16 bits	|
	| Source Address	| Destination Address	|
	|___________________________________________|
	*/
	UCHAR SourceAddress[16];		// Source Address (128 bits) 
	UCHAR DestinationAddress[16];	// Destination Address (128 bits) 
};

/* 
 * taken from wiki
 *
Protocol Number	Protocol Name	Abbreviation
1	Internet Control Message Protocol	ICMP
2	Internet Group Management Protocol	IGMP
6	Transmission Control Protocol	TCP
17	User Datagram Protocol	UDP
41	IPv6 encapsulation	ENCAP
89	Open Shortest Path First	OSPF
132	Stream Control Transmission Protocol	SCTP
* go to http://en.wikipedia.org/wiki/List_of_IP_protocol_numbers 
* for a complete list of protocol values in IP Header
*
* these are payload protocols i.e. what data IP packet is carrying.
*/
enum IPHeaderProtocolMeanings{
	IPHP_ICMP = 1,
	IPHP_IGMP = 2,
	IPHP_TCP = 6,
	IPHP_UDP = 17,
	IPHP_ENCAP = 41,
	IPHP_OSPF = 89,
	IPHP_SCTP = 132
};


void DebugPrintIPv4Header(struct IPv4_HEADER * ipv4h);


#endif