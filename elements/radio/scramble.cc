/*
 * scramble.{cc,hh} -- element scrambles packet data (for BIM-4xx-RS232 radios)
 * Robert Morris
 *
 * Copyright (c) 1999-2000 Massachusetts Institute of Technology.
 *
 * This software is being provided by the copyright holders under the GNU
 * General Public License, either version 2 or, at your discretion, any later
 * version. For more information, see the `COPYRIGHT' file in the source
 * distribution.
 */

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif
#include "scramble.hh"

Scramble::Scramble()
{
  add_input();
  add_output();
}

Scramble::~Scramble()
{
}

static unsigned char pattern[] = {
#if 1
0xa5, 0x0f, 0xe1, 0xe1, 0xe1, 0xc3, 0xe1, 0xc3,
0x3c, 0xc3, 0xd2, 0x1e, 0x87, 0x4b, 0x87, 0xa5,
0xe1, 0x4b, 0xe1, 0x0f, 0x3c, 0x87, 0x87, 0x1e,
0x2d, 0xa5, 0xb4, 0x69, 0x78, 0x1e, 0xc3, 0x1e,
0x2d, 0xb4, 0xf0, 0x1e, 0x78, 0xe1, 0xd2, 0xa5,
0xb4, 0xa5, 0xb4, 0x3c, 0xe1, 0x4b, 0xe1, 0xc3,
0x96, 0xd2, 0xc3, 0xc3, 0x5a, 0x5a, 0xe1, 0x78,
0xf0, 0x96, 0xe1, 0x69, 0xb4
#else
  0x2b, 0x1e, 0xc3, 0x43, 0xe2, 0xe7, 0xa2, 0xc7,
  0xf9, 0xe6, 0xc5, 0xbd, 0x0f, 0xf7, 0x4f, 0x0a,
  0x03, 0x16, 0x42, 0x3f, 0x18, 0x4f, 0x6f, 0x1c,
  0x7b, 0x2a, 0xc9, 0x93, 0x11, 0xbc, 0x26
#endif
};

Packet *
Scramble::simple_action(Packet *p)
{
  int i, len, j;

  p = p->uniqueify();
  len = p->length();
  j = 0;
  for(i = 0; i < len; i++){
    p->data()[i] ^= pattern[j];
    j++;
    if(j >= (int)sizeof(pattern))
      j = 0;
  }

  return(p);
}

EXPORT_ELEMENT(Scramble)
