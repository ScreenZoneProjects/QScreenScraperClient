#include "CResponse.hpp"

const QString CResponse::s_sRestAPIWordId = "id";
const QString CResponse::s_sRestAPIWordManufacturer = "compagnie";
const QString CResponse::s_sRestAPIWordNames = "noms";
const QString CResponse::s_sRestAPIWordNameAlt;
const QString CResponse::s_sRestAPIWordEditor = "editor";
const QString CResponse::s_sRestAPIWordDeveloper = "developer";
const QString CResponse::s_sRestAPIWordPlayerCount = "playerCount";
const QString CResponse::s_sRestAPIWordRating = "rating";
const QString CResponse::s_sRestAPIWordRotation = "rotation";
const QString CResponse::s_sRestAPIWordResolution = "resolution";
const QString CResponse::s_sRestAPIWordControlerType = "controlerType";
const QString CResponse::s_sRestAPIWordColors = "colors";
const QString CResponse::s_sRestAPIWordSynopsis = "synopsys";
const QString CResponse::s_sRestAPIWordClassification = "classification";
const QString CResponse::s_sRestAPIWordReleaseDates = "releaseDates";
const QString CResponse::s_sRestAPIWordGenres = "genres";
const QString CResponse::s_sRestAPIWordModes;
const QString CResponse::s_sRestAPIWordThemes;

const QString CResponse::s_sRestAPIWordMedias = "medias";

const QString CResponse::s_sRestAPIWordMediaScreenshots = "screenshots";
const QString CResponse::s_sRestAPIWordMediaFanarts = "fanarts";
const QString CResponse::s_sRestAPIWordMediaVideos = "videos";
const QString CResponse::s_sRestAPIWordMediaMarquees ="videos";
const QString CResponse::s_sRestAPIWordMediaScreenMarquees = "screenMarquees";

const QString CResponse::s_sRestAPIWordMediaWheels = "wheels";
const QString CResponse::s_sRestAPIWordMediaWheelsCarbon = "carbon";

const QString CResponse::s_sRestAPIWordMediaBox = "box";
const QString CResponse::s_sRestAPIWordMediaBoxTexture = "texture";
const QString CResponse::s_sRestAPIWordMediaBox2D = "2D";
const QString CResponse::s_sRestAPIWordMediaBox3D = "3DS";

const QString CResponse::s_sRestAPIWordMediaSupports = "supports";
const QString CResponse::s_sRestAPIWordMediaSupportsTexture = "texture";
const QString CResponse::s_sRestAPIWordMediaSupports2D = "2D";
const QString CResponse::s_sRestAPIWordMediaSupports3D = "3D";

const QString CResponse::s_sRestAPIWordMediaBezels = "bezels";
const QString CResponse::s_sRestAPIWordMediaBezel_4_3 = "4/3";
const QString CResponse::s_sRestAPIWordMediaBezel_16_9 = "16/9";
const QString CResponse::s_sRestAPIWordMediaBezel_16_10 = "16/10";

const QString CResponse::s_sRestAPIWordPlatforms = "platforms";

CResponse::CResponse()
{

}

bool CResponse::parse(QString stringHeader)
{
	// TODO ERROR
	return false;
}

bool CResponse::parseJson(const QJsonObject& oJsonHeader)
{
	// TODO ERROR
	return false;
}

bool CResponse::parseXML()
{
	// TODO ERROR
	return false;
}

bool CResponse::parseText()
{
	// TODO ERROR
	return false;
}
