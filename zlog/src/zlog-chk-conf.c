/*
 * This file is part of the zlog Library.
 *
 * Copyright (C) 2011 by Hardy Simpson <HardySimpson1984@gmail.com>
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

#include "fmacros.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include <unistd.h>

#include "zlog.h"

#if 1


int main(int argc, char *argv[])
{
	int rc = 0;
	
	int quiet = 0;
	static const char *help = 
		"Useage: zlog-chk-conf [conf files]...\n"
		"\t-q,\tsuppress non-error message\n"
		"\t-h,\tshow help message\n"
		"\t-v,\tshow zlog library's git version\n";

	static const char *cfg_file = "D:\\tmp\\zlog.conf";	

#ifndef _MSC_VER
	int op;
	while((op = getopt(argc, argv, "qhv")) > 0) {
		if (op == 'h') {
			puts(help);
			return 0;
		} else if (op == 'v') {
			printf("zlog git version[%s]\n", zlog_git_sha1);
			return 0;
		} else if (op == 'q') {
			quiet = 1;
		}
	}

	argc -= optind;
	argv += optind;
#endif

	if (argc == 0) {
		puts(help);
		return -1;
	}

#ifdef _MSC_VER
#define setenv(a,b,c) _putenv_s(a,b)
#endif

#ifdef _MSC_VER
	setenv("ZLOG_PROFILE_ERROR", "d:\\tmp\\stderr", 1);
	setenv("ZLOG_CHECK_FORMAT_RULE", "1", 1);
#else
	setenv("ZLOG_PROFILE_ERROR", "/dev/stderr", 1);
	setenv("ZLOG_CHECK_FORMAT_RULE", "1", 1);
#endif


	while (argc > 0) {
		//rc = zlog_init(*argv);
		rc = zlog_init(cfg_file);
		if (rc) {
			printf("\n---[%s] syntax error, see error message above\n",
				*argv);
			exit(2);
		} else {
			zlog_category_t *my_cat= zlog_get_category("my_cat");
			if (!my_cat) {
				printf("get cat fail\n");
				zlog_fini();
				return -2;
			}
			
			zlog_info(my_cat, "hello, zlog");
			zlog_debug(my_cat, "hello, zlog");
			printf("my_cat\n");

			zlog_fini();
			if (!quiet) {
				printf("--[%s] syntax right\n", *argv);
			}
		}
		argc--;
		argv++;
	}

	exit(0);
}

#endif

