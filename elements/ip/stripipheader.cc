/*
 * stripipheader.{cc,hh} -- element removes IP header based on annotation
 * Eddie Kohler
 *
 * Copyright (c) 2000 Massachusetts Institute of Technology
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, subject to the conditions
 * listed in the Click LICENSE file. These conditions include: you must
 * preserve this copyright notice, and you cannot mention the copyright
 * holders in advertising related to the Software without their permission.
 * The Software is provided WITHOUT ANY WARRANTY, EXPRESS OR IMPLIED. This
 * notice is a summary of the Click LICENSE file; the license in that file is
 * legally binding.
 */

#include <click/config.h>
#include "stripipheader.hh"
#include <clicknet/ip.h>

StripIPHeader::StripIPHeader()
  : Element(1, 1)
{
  MOD_INC_USE_COUNT;
}

StripIPHeader::~StripIPHeader()
{
  MOD_DEC_USE_COUNT;
}

Packet *
StripIPHeader::simple_action(Packet *p)
{
  p->pull((int)p->ip_header_offset() + p->ip_header_length());
  return p;
}

EXPORT_ELEMENT(StripIPHeader)
ELEMENT_MT_SAFE(StripIPHeader)
