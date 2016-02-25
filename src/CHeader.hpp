#pragma once

#include <QtGlobal>
#include <QDateTime>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

class CHeader
{
public:
	CHeader();

	bool parse(QString stringHeader);
	bool parseJson(const QJsonObject& oJsonHeader);
	bool parseXML();
	bool parseText();

private:
	quint8 m_ui8APIMajorVersion;
	quint8 m_ui8APIMinorVersion;
	QDateTime m_oDateTime;
	QString m_sCommandRequested;
	bool m_bSuccess;
	QString m_sError;

	// Header
	static const QString s_sRestAPIWordHeader;
	static const QString s_sRestAPIWordHeaderAPIVersion;
	static const QString s_sRestAPIWordHeaderDateTime;
	static const QString s_sRestAPIWordHeaderCommandRequested;
	static const QString s_sRestAPIWordHeaderSuccess;
	static const QString s_sRestAPIWordHeaderError;
};
