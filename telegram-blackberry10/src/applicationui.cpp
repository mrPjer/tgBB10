/*
 * Copyright (c) 2011-2014 BlackBerry Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "applicationui.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/LocaleHandler>

#include "util/timer.hpp"
#include "util/countries.hpp"
#include "util/AvatarUtil.hpp"

#include "api/TgSession.hpp"
#include "api/model/ChatListItem.hpp"

#include "model/ChatsDataModel.hpp"
#include "model/ContactsDataModel.hpp"
#include "model/ChatDataModel.hpp"

#include "config.hpp"

#ifdef TG_API_MOCK
#include "api/apiRegAuth.hpp"
#include "api/apiContacts.hpp"
#include "api/apiMessages.hpp"
#endif

#ifdef TG_API_TG
#include "api/tgApi.hpp"
#endif

using namespace bb::cascades;

ApplicationUI::ApplicationUI() :
        QObject()
{
    // Register our Timer class in QML
    qmlRegisterType<Timer>("Timer", 1, 0, "Timer");

    qmlRegisterUncreatableType<ChatListItem>("TgApi", 1, 0, "ChatListItem",
            "Should only be received as an API response");

    qmlRegisterType<TgSession>("TgApi", 1, 0, "Session");
    qmlRegisterType<TelegramNamespace>("TgApi", 1, 0, "ContactStatus");
    qmlRegisterType<ChatsDataModel>("TgApi", 1, 0, "ChatsDataModel");
    qmlRegisterType<ContactsDataModel>("TgApi", 1, 0, "ContactsDataModel");
    qmlRegisterType<ChatDataModel>("TgApi", 1, 0, "ChatDataModel");
    qmlRegisterType<AvatarUtil>("TgApi", 1, 0, "AvatarUtil");
#ifdef TG_API_MOCK
    // Register out Registration API in QML
    qmlRegisterType<APIRegAuth>("TgApi", 1, 0, "RegistrationApi");
    qmlRegisterType<APIContacts>("TgApi", 1, 0, "ContactsApi");
    qmlRegisterType<APIMessages>("TgApi", 1, 0, "MessagesApi");
#endif
#ifdef TG_API_TG
    qmlRegisterType<tgApi>("TgApi", 1, 0, "RegistrationApi");
    qmlRegisterType<tgApi>("TgApi", 1, 0, "ContactsApi");
    qmlRegisterType<tgApi>("TgApi", 1, 0, "MessagesApi");
    qmlRegisterType<tgApi>("TgApi", 1, 0, "UserInfoApi");
#endif

    // prepare the localization
    m_pTranslator = new QTranslator(this);
    m_pLocaleHandler = new LocaleHandler(this);

    bool res = QObject::connect(m_pLocaleHandler, SIGNAL(systemLanguageChanged()), this,
            SLOT(onSystemLanguageChanged()));
    // This is only available in Debug builds
    Q_ASSERT(res);
    // Since the variable is not used in the app, this is added to avoid a
    // compiler warning
    Q_UNUSED(res);

    // initial load
    onSystemLanguageChanged();

    QString pageAsset;

#ifdef TG_API_TG
    TgSession session;

    if (session.isSessionStored()) {
        QByteArray secret = session.session();
        qDebug() << "Existing session already present - " << secret;

        tgApi api;
        api.restoreConnection(secret);
        pageAsset = "asset:///main/MainPage.qml";
    } else {
        qDebug() << "No existing session";

        tgApi api;
        api.initConnection(QLatin1String(TG_API_IP), TG_API_PORT);
        pageAsset = "asset:///intro/IntroWithPane.qml";
    }
#endif
#ifdef TG_API_MOCK
    pageAsset = "asset:///main.qml";
#endif

    // Create scene document from main.qml asset, the parent is set
    // to ensure the document gets destroyed properly at shut down.
    QmlDocument *qml = QmlDocument::create(pageAsset).parent(this);

    // Create root object for the UI
    AbstractPane *root = qml->createRootObject<AbstractPane>();

    // Register the countries so they are available in QML
    QDeclarativePropertyMap *countries = CountryReader::getCountries();
    qml->setContextProperty("countries", countries);

    // Set created root object as the application scene
    Application::instance()->setScene(root);
}

void ApplicationUI::onSystemLanguageChanged()
{
    QCoreApplication::instance()->removeTranslator(m_pTranslator);
    // Initiate, load and install the application translation files.
    QString locale_string = QLocale().name();
    QString file_name = QString("telegram_blackberry10_%1").arg(locale_string);
    if (m_pTranslator->load(file_name, "app/native/qm")) {
        QCoreApplication::instance()->installTranslator(m_pTranslator);
    }
}
