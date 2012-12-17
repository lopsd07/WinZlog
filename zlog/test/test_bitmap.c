/*
 * This file is part of the zlog Library.
 *
 * Copyright (C) 2011 by Hardy Simpson <HardySimpson@gmail.com>
 *
 * The zlog Library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * The zlog Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with the zlog Library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include "zlog.h"

int zlog_test();

int main(int argc, char** argv)
{
	unsigned char aa[32];
	int i, j;

	i = 1;
	j = 2;
	zlog_init("AA");


// 	i = atoi(argv[1]);
// 	j = atoi(argv[2]);
	printf("Hello.\n");
	zlog_test();
// 
// 	memset(aa, 0x00, sizeof(aa));
// 
// 	aa[i/8] |=  ~(0xFF << (8 - i % 8));
// 	memset(aa + i/8 + 1, 0xFF, sizeof(aa) - i/8 - 1);

// 	hdzlog_info(aa, sizeof(aa));
// 
// 	dzlog_info("%0x", aa[j/8]);
// 	dzlog_info("%0x", aa[j/8] >> 6);
// 
// 	dzlog_info("%0x", ~((aa[j/8] >> (7 - j % 8)) & 0x01) );
// 
// 	zlog_fini();
	
	return 0;
}

int zlog_test()
{
	int rc;
	zlog_category_t *c;

	rc = zlog_init("d:\\tmp\\zlog.conf");
	if (rc) {
		printf("init failed\n");
		return -1;
	}

	c = zlog_get_category("my_cat");
	if (!c) {
		printf("get cat fail\n");
		zlog_fini();

		return -2;
	}


	zlog_info(c, "hello, zlog");
	zlog_debug(c, "hello, zlog");
	zlog_error(c, "hello, zlog");

	zlog_fini();
	printf("exit.\n");

	return 0;
} 