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
