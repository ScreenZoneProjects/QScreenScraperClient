#pragma once

#include <QNetworkAccessManager>
#include <QUrlQuery>
#include <QNetworkReply>
#include <QUrl>

#include <QFile>
#include <QFileInfo>

#include "QScreenScraperAPIClient.hpp"

class CRequest : public QObject
{
	Q_OBJECT

public:
	CRequest(QUrl oUrl);
	bool send();
	bool abortIt();
	const QByteArray* getResult();

private:
	bool requestCommand(QUrlQuery oUrlQuery);

	bool m_bIsFile;
	bool m_bIsFinished;
	bool m_bIsSuccess;
	QFileInfo m_oFilePath;

	QByteArray m_oResult;

private:
	QNetworkAccessManager* m_pNetworkAccessManager;
	QScreenScraperAPIClient* m_pScreenScraperAPIClient;

	QByteArray m_ui8VRequestHeaderUserAgent;

private Q_SLOTS:
	void slotNetworkReplyFinished();
	void slotNetworkReplyProgress(qint64 i64BytesReceived, qint64 i64BytesTotal);
	void slotNetworkReplyReadyRead();
	void slotNetworkReplyError(QNetworkReply::NetworkError oNetworkError);
	void slotNetworkReplySSLErrors(const QList<QSslError>& voSSLErrors);
	void slotNetworkReplySSLErrors(QNetworkReply* pNetworkReply, const QList<QSslError>& voSSLErrors);
};
