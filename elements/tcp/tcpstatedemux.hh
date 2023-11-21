/*
 * tcpstatedemux.{cc,hh} -- TCP state demultiplexer
 * Rafael Laufer
 *
 * Copyright (c) 2017 Nokia Bell Labs
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer 
 *    in the documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *
 */

#ifndef CLICK_TCPSTATEDEMUX_HH
#define CLICK_TCPSTATEDEMUX_HH
#include <click/element.hh>
CLICK_DECLS

/*
=c

TCPStateDemux

=s tcp

demultiplexes packets according to TCP connection state.

=d

Demultiplexes packets according to their TCP connection state. The connection
state is read from the TCP state annotation. If the annotation has not been set
then the connection is assumed to be CLOSED.

Packets whose connection is in: 
- CLOSED state are sent to output 0;
- LISTEN state are sent to output 1;
- SYN_SENT state are sent to output 2;
- any other state are sent to output 3.

=a TCPState */


class TCPStateDemux final : public Element { public:

	TCPStateDemux() CLICK_COLD;

	const char *class_name() const { return "TCPStateDemux"; }
	const char *port_count() const { return "1/4"; }
	const char *processing() const { return PUSH; }

	void push(int, Packet *) final;
};

CLICK_ENDDECLS
#endif
