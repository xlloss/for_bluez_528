/*
 *
 *  OBEX Server
 *
 *  Copyright (C) 2007-2010  Nokia Corporation
 *
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#include <dbus/dbus.h>

#define OBEXD_SERVICE  "org.bluez.obex"

struct obex_session;
struct obex_transfer;

void manager_register_session(struct obex_session *os);
void manager_unregister_session(struct obex_session *os);

struct obex_transfer *manager_register_transfer(struct obex_session *os);
void manager_unregister_transfer(struct obex_transfer *transfer);
void manager_emit_transfer_started(struct obex_transfer *transfer);
void manager_emit_transfer_progress(struct obex_transfer *transfer);
void manager_emit_transfer_completed(struct obex_transfer *transfer);
int manager_request_authorization(struct obex_transfer *transfer, int32_t time,
					char **new_folder, char **new_name);

DBusConnection *manager_dbus_get_connection(void);
