#include "countries.hpp"

QDeclarativePropertyMap* CountryReader::getCountries()
{
    QDeclarativePropertyMap *result = new QDeclarativePropertyMap;

    result->insert("Croatia", QVariant(QString("+385")));
    result->insert("United Kingdom", QVariant(QString("+44")));

    return result;
}
