#ifndef CONFIG_HPP_
#define CONFIG_HPP_

/*
 * Define only one of the following constants.
 *
 * TG_API_MOCK will use the mock, offline API, while TG_API_TG will
 * connect to Telegram servers
 */

#define TG_API_MOCK
//#define TG_API_TG

/*
 * Determines whether the API will connect to the test DC or the
 * production one.
 *
 * The test DC is more suitable for testing API calls, but
 * is in turn harder to test with since regular users won't be able to send
 * you messages. It is recommended to leave this set to production for most
 * use cases.
 */
#define TG_API_PRODUCTION true

#ifdef TG_API_TG
#include "app_secrets.hpp"

#if TG_API_PRODUCTION

#define TG_API_IP TG_IP_PROD
#define TG_API_PORT TG_PORT_PROD

#else

#define TG_API_IP TG_IP_TEST
#define TG_API_PORT TG_PORT_TEST

#endif

#endif

#ifdef TG_API_MOCK
#ifdef TG_API_TG
#error "Only one TG_API may be defined!"
#endif
#endif

#ifndef TG_API_MOCK
#ifndef TG_API_TG
#error "At least one TG API must be defined!"
#endif
#endif

#endif
