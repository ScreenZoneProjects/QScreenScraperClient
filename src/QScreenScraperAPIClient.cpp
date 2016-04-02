#include "QScreenScraperAPIClient.hpp"
#include "CRequest.hpp"

#include <QMap>

const QString QScreenScraperAPIClient::s_sAPIClientName = "QScreenScraper";

// Response
const QString QScreenScraperAPIClient::s_sRestAPIWordResponse = "response";

//
const QString QScreenScraperAPIClient::s_sRestAPIWordClientId = "devid";
const QString QScreenScraperAPIClient::s_sRestAPIWordPassword = "devpassword";
const QString QScreenScraperAPIClient::s_sRestAPIWordSoftware = "softname";
const QString QScreenScraperAPIClient::s_sRestAPIWordOutput = "output";
const QString QScreenScraperAPIClient::s_sRestAPIWordCRC = "crc";
const QString QScreenScraperAPIClient::s_sRestAPIWordMD5 = "md5";
const QString QScreenScraperAPIClient::s_sRestAPIWordSHA1 = "sha1";

const QString QScreenScraperAPIClient::s_sRestAPIWordRomType = "romtype";
const QString QScreenScraperAPIClient::s_sRestAPIWordRomName = "romnom";
const QString QScreenScraperAPIClient::s_sRestAPIWordRomSize = "romtaille";

const QString QScreenScraperAPIClient::s_sRestAPIWordURLSystemList = "systemesListe.php";
const QString QScreenScraperAPIClient::s_sRestAPIWordURLSupportTypeList = "supportTypesListe.php";
const QString QScreenScraperAPIClient::s_sRestAPIWordURLRomTypeList = "romTypesListe.php";
const QString QScreenScraperAPIClient::s_sRestAPIWordURLSystemMedia = "mediaSysteme.php";
const QString QScreenScraperAPIClient::s_sRestAPIWordURLSystemMediaVideo = "mediaVideoSysteme.php";
const QString QScreenScraperAPIClient::s_sRestAPIWordURLGameinfo = "jeuInfos.php";
const QString QScreenScraperAPIClient::s_sRestAPIWordURLGameMedia = "mediaJeu.php";
const QString QScreenScraperAPIClient::s_sRestAPIWordURLGameMediaVideo = "mediaVideoJeu.php";

enum EPlatformType
{
	EPlatformType_Unknow = 0,
	EPlatformType_Console = 1
};

enum ESupportType
{
	ESupportType_Unknow = 0,
	ESupportType_Cartbridge = 1
};

enum ERomType
{
	ERomType_Unknow = 0,
	ERomType_Rom = 1,
	ERomType_ISO = 2,
	ERomType_Folder = 3
};

struct SSystemInfo
{
	quint64 m_ui64Id;
	QMap<QString, QString> m_mNames;
	EPlatformType m_ePlatformType;
	QString m_sManufacturer;
	QDate m_oBeginDate;
	QDate m_oEndDate;
	QMap<QString, QUrl> m_mMedias;
};

struct SGameInfo
{
	quint64 m_ui64Id;
	QMap<QString, QString> m_mNames;
	EPlatformType m_ePlatformType;
	QString m_sEditor;
	QString m_sDeveloper;
	qint8 m_i8PlayerCount;
	quint16 m_ui16Rotation;
	QMap<QString, QString> m_mSynopsis;
	QMap<QString, QString> m_mRating;
	QMap<QString, QDate> m_mReleaseDates;
	QDate m_oBeginDate;
	QDate m_oEndDate;
	QMap<QString, QUrl> m_mMedias;
};

QScreenScraperAPIClient::QScreenScraperAPIClient():
	m_uint16ServerPort(80),
	m_ui8MaxParallelDownloads(6)
{

}

bool QScreenScraperAPIClient::connect()
{
	if(m_oServerHostURL.isEmpty())
	{
		// TODO ERROR
		return false;
	}

	if(!m_oServerHostURL.isValid())
	{
		// TODO ERROR
		return false;
	}

	m_oNetworkAccessManager.connectToHost(m_oServerHostURL.toString(), m_uint16ServerPort);

	if(m_oNetworkAccessManager.networkAccessible() != QNetworkAccessManager::Accessible)
	{
		// TODO ERROR
		return false;
	}
}

bool QScreenScraperAPIClient::setProxy(QNetworkProxy::ProxyType eProxyType, QString sHostName, quint16 uint16Port, QString sUser, QString sPassword)
{
	QNetworkProxy l_oProxy(eProxyType, sHostName, uint16Port, sUser, sPassword);
	m_oNetworkAccessManager.setProxy(l_oProxy);
	QNetworkProxy::setApplicationProxy(l_oProxy);
	return true;
}

bool QScreenScraperAPIClient::requestPlatformList()
{
	QUrl l_oURL = m_oServerHostURL;
	l_oURL += s_sRestAPIWordURLSystemList + "?";
	QUrlQuery l_oURLQuery;
	l_oURLQuery.add(s_sRestAPIWordClientId, m_sUserId);
	l_oURLQuery.add(s_sRestAPIWordPassword, m_sUserPassword);
	l_oURLQuery.add(s_sRestAPIWordSoftware, m_sSoftwareName);
	l_oURLQuery.add(s_sRestAPIWordOutput, "json");
	l_oURL.setQuery(l_oURLQuery);
	CRequest l_oRequest;
	l_oRequest.requestCommand();

	return true;
}

bool QScreenScraperAPIClient::parsePlatformListResponse(const QString& sResponse)
{
	/*QJsonParseError l_oJsonParserError;
	QJsonDocument oJsonDocument = QJsonDocument::fromJson(sResponse.toUtf8(), &l_oJsonParserError);

	if(l_oJsonParserError.error != 0)
	{
		qDebug() << l_oJsonParserError.errorString();
		return false;
	}

	if(oJsonDocument.isNull())
	{
		qDebug() << "Invalid json document, exiting...";
		return false;
	}

	if(oJsonDocument.isObject())
	{
		QJsonObject l_oJsonObject = oJsonDocument.object();

		for (QJsonObject::ConstIterator l_iRoot = l_oJsonObject.begin(); l_iJsonObjectIterator != l_oJsonObject.end(); ++l_iJsonObjectIterator)
		{
			if(l_iRoot.key() == s_sRestAPIWordHeader)
			{
			else if(l_iJsonObjectIterator.key() == s_sRestAPIWordResponse)
			{
				l_bResponseFound = false;

			}
			else
			{
				QDebug() << "Unknow blabalba";
			}
		}

		QVariantMap l_oMainMap = l_oJsonObject.toVariantMap();
		QVariantMap l_oHeaderMap = l_oMainMap[s_sRestAPIWordHeader].toMap();



	}
	else
	{
		return false;
	}*/

	return true;
}

QString QScreenScraperAPIClient::getAPIClientName()
{
	return s_sAPIClientName;
}

quint8 QScreenScraperAPIClient::getMajorVersion()
{
	return s_ui8APIClientMajorVersion;
}

quint8 QScreenScraperAPIClient::getMinorVersion()
{
	return s_ui8APIClientMinorVersion;
}

QString QScreenScraperAPIClient::getVersion()
{
	return QString::number(s_ui8APIClientMajorVersion) + "." + QString::number(s_ui8APIClientMinorVersion);
}

QUrl QScreenScraperAPIClient::getServerHostURL() const
{
	return m_oServerHostURL;
}

void QScreenScraperAPIClient::setServerHostURL(const QUrl &oServerHostURL)
{
	m_oServerHostURL = oServerHostURL;
}

void QScreenScraperAPIClient::setServerPort(quint16 ui16ServerPort)
{
	m_uint16ServerPort = ui16ServerPort;
}

QString QScreenScraperAPIClient::getUserId() const
{
	return m_sUserId;
}

void QScreenScraperAPIClient::setUserId(const QString &sUserId)
{
	m_sUserId = sUserId;
}

void QScreenScraperAPIClient::setUserPassword(const QString &sPassword)
{
	m_sUserPassword = sPassword;
}

