#include "CHeader.hpp"

// Header
const QString CHeader::s_sRestAPIWordHeader = "header";
const QString CHeader::s_sRestAPIWordHeaderAPIVersion = "APIversion";
const QString CHeader::s_sRestAPIWordHeaderDateTime = "dateTime";
const QString CHeader::s_sRestAPIWordHeaderCommandRequested = "commandRequested";
const QString CHeader::s_sRestAPIWordHeaderSuccess = "success";
const QString CHeader::s_sRestAPIWordHeaderError = "error";

CHeader::CHeader():
	m_ui8APIMajorVersion(0),
	m_ui8APIMinorVersion(0),
	m_bSuccess(false)
{

}

bool CHeader::parse(QString stringHeader)
{
	return true;
}

bool CHeader::parseJson(const QJsonObject& oJsonHeader)
{
	for (QJsonObject::ConstIterator l_iHeader = oJsonHeader.begin(); l_iHeader != oJsonHeader.end(); ++l_iHeader)
	{
		if(l_iHeader.key() == s_sRestAPIWordHeaderAPIVersion)
		{
			if(l_iHeader.value().isString())
			{
				QStringList l_vsAPIVersion = l_iHeader.value().toString().split(".");

				if(l_vsAPIVersion.count() >= 2)
				{
					bool l_bConverstionSuccess = false;
					m_ui8APIMajorVersion = l_vsAPIVersion.at(0).toUShort(&l_bConverstionSuccess);
					m_ui8APIMinorVersion = l_vsAPIVersion.at(1).toUShort(&l_bConverstionSuccess);
				}
				else
				{
					// TODO ERROR
					return false;
				}
			}
			else
			{
				// TODO ERROR
				return false;
			}
		}
		else if(l_iHeader.key() == s_sRestAPIWordHeaderDateTime)
		{
			if(l_iHeader.value().isString())
			{
				m_oDateTime = QDateTime::fromString(l_iHeader.value().toString());
			}
			else
			{
				// TODO ERROR
				return false;
			}
		}
		else if(l_iHeader.key() == s_sRestAPIWordHeaderCommandRequested)
		{
			if(l_iHeader.value().isString())
			{
				m_sCommandRequested = l_iHeader.value().toString();
			}
			else
			{
				// TODO ERROR
				return false;
			}
		}
		else if(l_iHeader.key() == s_sRestAPIWordHeaderSuccess)
		{
			if(l_iHeader.value().isBool())
			{
				m_bSuccess = l_iHeader.value().toBool();
			}
			else
			{
				// TODO ERROR
				return false;
			}
		}
		else if(l_iHeader.key() == s_sRestAPIWordHeaderError)
		{
			if(l_iHeader.value().isString())
			{
				m_sError = l_iHeader.value().toString();
			}
			else
			{
				// TODO ERROR
				return false;
			}
		}
		else
		{
			// TODO ERROR
			return false;
		}
	}
}

bool CHeader::parseXML()
{
	// TODO ERROR
	return false;
}

bool CHeader::parseText()
{
	// TODO ERROR
	return false;
}
