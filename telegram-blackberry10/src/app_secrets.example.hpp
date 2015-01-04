#ifndef APP_SECRETS_HPP_
#define APP_SECRETS_HPP_

#include "config.hpp"

#ifdef TG_API_TG

/*
 * Define your API secrets here. You can obtain these by visiting
 *
 *     https://my.telegram.org
 */

#define TG_APP_ID 012345
#define TG_API_HASH "00000000000000000000000000000000"

#define TG_IP_TEST "0.0.0.0"
#define TG_PORT_TEST 443

#define TG_IP_PROD "0.0.0.0"
#define TG_PORT_PROD 443

#endif

#endif
