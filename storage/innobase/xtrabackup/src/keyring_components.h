/******************************************************
Copyright (c) 2021 Percona LLC and/or its affiliates.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; version 2 of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

*******************************************************/
#ifndef XB_KEYRING_COMPONENTS_H
#define XB_KEYRING_COMPONENTS_H

#include <components/keyrings/keyring_file/config/config.h>
#include <mysql.h>
namespace xtrabackup {
namespace components {
/** Data types */
extern std::unique_ptr<keyring_file::config::Config_pod> new_config_pod;
extern bool keyring_component_initialized;

/**
  Write backup keyring component config file

  @return false in case of error, true otherwise
*/
bool write_component_config_file();

/**
  Read server_uuid from backup-my.cnf

  @return false in case of error, true otherwise
*/
bool read_server_uuid();

/**
  Initialize Keyring component by querying config from a running server
  This is used at --backup

  @param [in]  connection       MYSQL connection to running server

  @return false in case of error, true otherwise
  @keyring_component_initialized false keyring component not initialized
  @keyring_component_initialized true  keyring component initialized
*/
bool keyring_init_online(MYSQL *connection);

/**
  Initialize Keyring component by reading xtrabackup_keyring_component.cnf file
  This is used at --prepare, --stats, --move-back, --copy-back

  @return false in case of error, true otherwise
  @keyring_component_initialized false keyring component not initialized
  @keyring_component_initialized true  keyring component initialized
*/
bool keyring_init_offline();

/** Initialize component service handles */
bool inititialize_service_handles();

/** Deinitialize component service handles */
void deinitialize_service_handles();
}  // namespace components
}  // namespace xtrabackup
#endif  // XB_KEYRING_COMPONENTS_H