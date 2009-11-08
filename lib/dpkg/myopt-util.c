/*
 * libdpkg - Debian packaging suite library routines
 * myopt-util.c - command line option utilities
 *
 * Copyright © 1994,1995 Ian Jackson <ian@chiark.greenend.org.uk>
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <config.h>
#include <compat.h>

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include <dpkg/i18n.h>
#include <dpkg/dpkg.h>
#include <dpkg/buffer.h>
#include <dpkg/myopt.h>

void
showcopyright(const struct cmdinfo *cip, const char *value)
{
	int fd;

	fd = open(COPYINGFILE, O_RDONLY);
	if (fd < 0)
		ohshite(_("cannot open GPL file"));
	fd_fd_copy(fd, 1, -1, "showcopyright");
	exit(0);
}

