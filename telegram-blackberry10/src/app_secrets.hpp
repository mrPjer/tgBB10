#ifndef APP_SECRETS_HPP_
#define APP_SECRETS_HPP_

/*
 * Define your API secrets here. You can obtain these by visiting
 *
 *      https://my.telegram.org
 *
 * Avoid committing this file unless you are changing the default placeholders!
 *
 * Once you're done inserting your secrets, delete the #error line.
 *
 * Since you (mostly) don't want local changes to this file tracked by git,
 * you can tell it to assume it's kept unchanged by issuing
 *
 *      git update-index --assume-unchanged app_secrets.hpp
 *
 * In case you do need to make changes to the template file, simply undo the
 * previous command by issuing
 *
 *      git update-index --no-assume-unchanged app_secrets.hpp
 *
 */

#error "Remember to set your own API secrets!"

#define TG_APP_ID 012345
#define TG_API_HASH "00000000000000000000000000000000"

#define TG_IP_TEST "0.0.0.0"
#define TG_PORT_TEST 443

#define TG_IP_PROD "0.0.0.0"
#define TG_PORT_PROD 443

#endif
