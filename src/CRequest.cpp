#include "CRequest.hpp"

CRequest::CRequest(const QUrl& oQUrl):
	m_oQUrl(oQUrl)
{
}

bool send()
{
	return true;
}

bool abortIt()
{
	return true;
}

bool CRequest::requestCommand()
{
	QNetworkRequest l_oRequest(m_oQUrl);
	l_oRequest.setRawHeader(QByteArray("Host"), m_pScreenScraperAPIClient->getServerHostURL().toString().toUtf8());
	QString l_sUserAgent = m_pScreenScraperAPIClient->getAPIClientName() + " " + m_pScreenScraperAPIClient->getVersion();
	l_oRequest.setRawHeader(QByteArray("User-Agent"), l_sUserAgent.toUtf8());
	l_oRequest.setRawHeader(QByteArray("Date"), QDateTime::currentDateTime().toString(Qt::RFC2822Date).toUtf8());

	QNetworkReply* l_pNetworkReply = m_pNetworkAccessManager->get(l_oRequest);
	connect(l_pNetworkReply, SIGNAL(readyRead()),                        this, SLOT(slotNetworkReplyReadyRead()));
	connect(l_pNetworkReply, SIGNAL(finished()),                         this, SLOT(slotNetworkReplyFinished()));
	connect(l_pNetworkReply, SIGNAL(downloadProgress(qint64,qint64)),    this, SLOT(slotNetworkReplyProgress(qint64,qint64)));
	connect(l_pNetworkReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(slotNetworkReplyError(QNetworkReply::NetworkError)));
	connect(l_pNetworkReply, SIGNAL(sslErrors(QList<QSslError>)),        this, SLOT(slotNetworkReplySSLErrors(QList<QSslError>)));

	return true;
}

void CRequest::slotNetworkReplyFinished()
{
	QNetworkReply *pNetworkReply = qobject_cast<QNetworkReply*>(sender());

	if(m_bIsFile)
	{
		QFile l_oFile(m_oFilePath.absoluteFilePath());

		if(l_oFile.open(QFile::WriteOnly))
		{
			if(l_oFile.write(pNetworkReply->readAll()) == -1)
			{
				// TODO ERROR
			}

			if(!l_oFile.flush())
			{
				// TODO ERROR
			}

			l_oFile.close();
		}
		else
		{

		}
	}
	else
	{
		m_oResult = pNetworkReply->readAll();
	}

	pNetworkReply->deleteLater();
}

void CRequest::slotNetworkReplyProgress(qint64 i64BytesReceived, qint64 i64BytesTotal)
{
	if (i64BytesTotal != -1)
	{
	}
}

void CRequest::slotNetworkReplyReadyRead()
{

}

void CRequest::slotNetworkReplyError(QNetworkReply::NetworkError oNetworkError)
{
	QNetworkReply *pNetworkReply = qobject_cast<QNetworkReply*>(sender());
}

void CRequest::slotNetworkReplySSLErrors(QNetworkReply* pNetworkReply, const QList<QSslError>& voSSLErrors)
{

}

void CRequest::slotNetworkReplySSLErrors(const QList<QSslError>& voSSLErrors)
{
  qDebug() << "QScreenScraperAPIClient::slotNetworkReplySSLErrors";

  foreach (const QSslError& oSSLError, voSSLErrors)
  {
	qDebug() << "SSL error: '" << (int)oSSLError.error() << "' ;" << oSSLError.errorString();
  }

  //m_networkReply->ignoreSslErrors();
}
