#pragma once

#include "qscreenscraperapiclient_global.hpp"
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkProxy>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QUrlQuery>
#include <QByteArray>

#include <QQueue>

class QSCREENSCRAPERAPICLIENTSHARED_EXPORT QScreenScraperAPIClient : public QObject
{
	Q_OBJECT

public:
	QScreenScraperAPIClient();
	bool connect();

	bool setProxy(QNetworkProxy::ProxyType eProxyType, QString sHostName, quint16 uint16Port, QString sUser, QString sPassword);

	QString getUserId() const;
	void setUserId(const QString &sUserId);
	void setUserPassword(const QString &sPassword);

	QUrl getServerHostURL() const;
	void setServerHostURL(const QUrl &oServerHostURL);

	void setServerPort(quint16 ui16ServerPort);

	static quint8 getMajorVersion();
	static quint8 getMinorVersion();
	static QString getVersion();

	static QString getAPIClientName();

private:
	bool requestPlatformList();
	bool requestPlatformInformation(quint32 ui32PlatformId);
	bool requestGameInformation(quint32 ui32GameId);
	bool requestRomInformation();
	bool requestRomTypesList();
	bool requestSupportTypesList();

	bool readJsonHeader(const QJsonDocument& oJsonDocument);
	bool readJsonResponse(const QJsonDocument& oJsonDocument);

	bool parsePlatformListResponse(const QString& sResponse);
	bool parsePlatformInformationResponse(const QString& sResponse);
	bool parsePlatformGameResponse(const QString& sResponse);
	bool parseRomTypeListResponse(const QString& sResponse);
	bool parseSupportTypeListResponse(const QString& sResponse);

	bool downloadFile(const QUrl& url,const QString& path);

private:
	QNetworkAccessManager m_oNetworkAccessManager;

	QUrl m_oServerHostURL;
	quint16 m_uint16ServerPort;

	quint8 m_ui8MaxParallelDownloads;
	QQueue<QUrl> m_voDownloadQueue;
	QList<QNetworkReply *> m_vpCurrentDownloads;

	QString m_sUserId;
	QString m_sUserPassword;

	QString m_sSoftwareName;

	// Static strings

	// API Library
	static const QString s_sAPIClientName;
	static const quint8 s_ui8APIClientMajorVersion = 0;
	static const quint8 s_ui8APIClientMinorVersion = 1;

	// Response
	static const QString s_sRestAPIWordResponse;

	static const QString s_sRestAPIWordClientId;
	static const QString s_sRestAPIWordPassword;
	static const QString s_sRestAPIWordSoftware;
	static const QString s_sRestAPIWordOutput;
	static const QString s_sRestAPIWordCRC;
	static const QString s_sRestAPIWordMD5;
	static const QString s_sRestAPIWordSHA1;
	static const QString s_sRestAPIWordPlatformId;

	static const QString s_sRestAPIWordRomType;
	static const QString s_sRestAPIWordRomName;
	static const QString s_sRestAPIWordRomSize;

	static const QString s_sRestAPIWordURLSystemList;
	static const QString s_sRestAPIWordURLSupportTypeList;
	static const QString s_sRestAPIWordURLRomTypeList;
	static const QString s_sRestAPIWordURLSystemMedia;
	static const QString s_sRestAPIWordURLSystemMediaVideo;
	static const QString s_sRestAPIWordURLGameinfo;
	static const QString s_sRestAPIWordURLGameMedia;
	static const QString s_sRestAPIWordURLGameMediaVideo;
};
