#pragma once

#include <QString>
#include <QJsonObject>

class CResponse
{
public:
	CResponse();

	bool parse(QString stringHeader);
	bool parseJson(const QJsonObject& oJsonHeader);
	bool parseXML();
	bool parseText();

private:

	static const QString s_sRestAPIWordId;
	static const QString s_sRestAPIWordManufacturer;
	static const QString s_sRestAPIWordNames;
	static const QString s_sRestAPIWordNameAlt;
	static const QString s_sRestAPIWordEditor;
	static const QString s_sRestAPIWordDeveloper;
	static const QString s_sRestAPIWordPlayerCount;
	static const QString s_sRestAPIWordRating;
	static const QString s_sRestAPIWordRotation;
	static const QString s_sRestAPIWordResolution;
	static const QString s_sRestAPIWordControlerType;
	static const QString s_sRestAPIWordColors;
	static const QString s_sRestAPIWordSynopsis;
	static const QString s_sRestAPIWordClassification;
	static const QString s_sRestAPIWordReleaseDates;
	static const QString s_sRestAPIWordGenres;
	static const QString s_sRestAPIWordModes;
	static const QString s_sRestAPIWordThemes;

	static const QString s_sRestAPIWordMedias;

	static const QString s_sRestAPIWordMediaScreenshots;
	static const QString s_sRestAPIWordMediaFanarts;
	static const QString s_sRestAPIWordMediaVideos;
	static const QString s_sRestAPIWordMediaMarquees;
	static const QString s_sRestAPIWordMediaScreenMarquees;

	static const QString s_sRestAPIWordMediaWheels;
	static const QString s_sRestAPIWordMediaWheelsCarbon;

	static const QString s_sRestAPIWordMediaBox;
	static const QString s_sRestAPIWordMediaBoxTexture;
	static const QString s_sRestAPIWordMediaBox2D;
	static const QString s_sRestAPIWordMediaBox3D;

	static const QString s_sRestAPIWordMediaSupports;
	static const QString s_sRestAPIWordMediaSupportsTexture;
	static const QString s_sRestAPIWordMediaSupports2D;
	static const QString s_sRestAPIWordMediaSupports3D;

	static const QString s_sRestAPIWordMediaBezels;
	static const QString s_sRestAPIWordMediaBezel_4_3;
	static const QString s_sRestAPIWordMediaBezel_16_9;
	static const QString s_sRestAPIWordMediaBezel_16_10;

	static const QString s_sRestAPIWordPlatforms;
};
