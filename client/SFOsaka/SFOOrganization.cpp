#include "SFOOrganization.h"

#include <QDebug>
#include <QGeoCoordinate>
#include <QVariant>

const QString SFOOrganization::IdKey                 = "id";
const QString SFOOrganization::NameKey               = "name";
const QString SFOOrganization::NameJpKey             = "name_jp";
const QString SFOOrganization::CategoryKey           = "category";
const QString SFOOrganization::DescriptionKey        = "description";
const QString SFOOrganization::DescriptionJpKey      = "description_jp";
const QString SFOOrganization::ShortDescriptionKey   = "shortDescription";
const QString SFOOrganization::ShortDescriptionJpKey = "shortDescription_jp";
const QString SFOOrganization::URLKey                = "url";
const QString SFOOrganization::ImageURLKey           = "imageUrl";

const QString SFOOrganization::ModificationKey       = "modificationDate";

SFOOrganization::SFOOrganization(QObject *parent) : QObject(parent)
{

}

SFOOrganization::SFOOrganization(const QJsonObject& jsonObject) :
    SFOOrganization(jsonObject.toVariantMap())
{
}

SFOOrganization::~SFOOrganization()
{
}

SFOOrganization::SFOOrganization(const QVariantMap& dataMap)
{
    _id = dataMap[IdKey].toString();
    _name = dataMap[NameKey].toString();
    _nameJp = dataMap[NameJpKey].toString();
    _category = dataMap[CategoryKey].toString();
    _description = dataMap[DescriptionKey].toString();
    _descriptionJp = dataMap[DescriptionJpKey].toString();
    _shortDescription = dataMap[ShortDescriptionKey].toString();
    _shortDescriptionJp = dataMap[ShortDescriptionJpKey].toString();
    QString modDate = dataMap[ModificationKey].toString();
    _modificationDate = QDateTime::fromString(modDate,Qt::ISODate);
    _url = dataMap[URLKey].toString();
    _imageUrl = dataMap[ImageURLKey].toString();
}

QJsonObject
SFOOrganization::ToJson() const
{
    // We provide a virtual _ToVariantMap for subclasses to override (or
    // more likely, enhance)
    return QJsonObject::fromVariantMap(_ToVariantMap());
}

QString
SFOOrganization::GetName_locale() const
{
    QString localeName = QLocale::system().name();
    if (localeName == "ja_JP") {
        return GetNameJp();
    } else {
        return GetName();
    }
}

QString
SFOOrganization::GetCategory_locale() const
{
    return GetCategory();
}

QString
SFOOrganization::GetDescription_locale() const
{
    QString localeName = QLocale::system().name();
    if (localeName == "ja_JP") {
        return GetDescriptionJp();
    } else {
        return GetDescription();
    }
}

QString
SFOOrganization::GetId() const
{
    return _id;
}

QString
SFOOrganization::GetName() const
{
    return _name;
}

QString
SFOOrganization::GetNameJp() const
{
    return _nameJp;
}

QString
SFOOrganization::GetCategory() const
{
    return _category;
}

QString
SFOOrganization::GetDescription() const
{
    return _description;
}

QString
SFOOrganization::GetDescriptionJp() const
{
    return _descriptionJp;
}

QString
SFOOrganization::GetShortDescription() const
{
    return _shortDescription;
}

QString
SFOOrganization::GetShortDescriptionJp() const
{
    return _shortDescriptionJp;
}

QDateTime
SFOOrganization::GetModificationDate() const
{
    return _modificationDate;
}

QString
SFOOrganization::GetURL() const
{
    return _url;
}

QString
SFOOrganization::GetImageURL() const
{
    return _imageUrl;
}

QVariantMap
SFOOrganization::_ToVariantMap() const
{
    QVariantMap dataMap;

    dataMap[IdKey] = _id;
    dataMap[NameKey] = _name;
    dataMap[NameJpKey] = _nameJp;
    dataMap[CategoryKey] = _category;
    dataMap[DescriptionKey] = _description;
    dataMap[DescriptionJpKey] = _descriptionJp;
    dataMap[ShortDescriptionKey] = _shortDescription;
    dataMap[ShortDescriptionJpKey] = _shortDescriptionJp;
    dataMap[ModificationKey] = _modificationDate.toString(Qt::ISODate);
    dataMap[ImageURLKey] = _imageUrl;
    dataMap[URLKey] = _url;

    return dataMap;
}
