#include "countries.hpp"
#include <qfile.h>
#include <qmap.h>

QDeclarativePropertyMap* CountryReader::getCountries()
{
    QDeclarativePropertyMap *result = new QDeclarativePropertyMap;

    QMap<QByteArray, QByteArray> temporaryData;

    QFile file("app/native/assets/login/countries.txt");

    Q_ASSERT(file.exists());

    bool opened = file.open(QIODevice::ReadOnly | QIODevice::Text);

    Q_ASSERT(opened);

    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        QList<QByteArray> parts = line.split(';');
        QByteArray countryCode = parts.at(0);
        QByteArray country = parts.at(2);

        temporaryData.insert(country, countryCode);
    }

    file.close();

    for (QMap<QByteArray, QByteArray>::iterator it = temporaryData.begin();
            it != temporaryData.end(); ++it) {
        result->insert(it.key(), it.value());
    }

    return result;
}
