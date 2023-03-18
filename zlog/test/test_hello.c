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
#include "zlog.h"
#include <Windows.h>

int main(int argc, char** argv)
{
	int rc;
	zlog_category_t *zc;
	getchar();

	rc = zlog_init("test_hello.conf");
	
	//rc = zlog_init("");
	
	if (rc) {
		printf("init failed\n");
		return -1;
	}

	zc = zlog_get_category("my_cat");
	if (!zc) {
		printf("get cat fail\n");
		zlog_fini();
		return -2;
	}
	while(1)
	{
	zlog_info(zc, "hello,�ӵ����Ŀ� zlog");
	//Sleep(10);
	};


	zlog_fini();
	getchar();
	getchar();
	
	return 0;
}
