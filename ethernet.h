#ifndef FLTR_ETHERNET_H
#define FLTR_ETHERNET_H

struct ETH_HEADER {
	UCHAR DestinationAddress[6];
	UCHAR SourceAddress[6];
	USHORT EthType;
};

void DebugPrintEthHeader(struct ETH_HEADER *eh);

#endif