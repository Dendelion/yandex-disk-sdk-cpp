#include <string>
#include <list>
#include <catch.hpp>
#include <yadisk/client.hpp>
using ydclient = yadisk::Client;
#include <url/path.hpp>
using url::path;

TEST_CASE("download valid file with valid token", "[client][download][file][place]") {

	std::string token = "AQAAAAATPnx3AAQXOJS1w4zmPUdrsJNR1FATxEM";
	path from{ "/yandexTest/1/test.docx" };
  string to = "../test/";
	ydclient client{ token };
	auto info = client.download(from,to);
	REQUIRE(not info.empty());
	auto msg = info["href"].get<std::string>();
	REQUIRE(msg == "https://downloader.disk.yandex.ru/disk/6c231d6ff45af113d8c9680c2096d3c0436e2bf2025c283128fcb25f68f4b09e/5902a834/L74dejbAgg_ikiau13FAuffDyQOEXTIzdMRDbKBFxlbrARQZFZKU3DzUAe4KbtFFsL8sU_rJ8XwWxyl7dqnebA%3D%3D?uid=274402661&filename=test.docx&disposition=attachment&hash=&limit=0&content_type=application%2Fvnd.openxmlformats-officedocument.wordprocessingml.document&fsize=11201&hid=2ecdfcf4e9eea0cc498bc50ea55a6e42&media_type=document&tknv=v2&etag=d241d0894b53968635dbd4e1ec8c6659");
}

TEST_CASE("download with invalid token", "[client][download][file][place]") {

	std::string token = "invalid-token";
	path from{ "/yandexTest/1/test.docx" };
  string to = "../test/";
	ydclient client{ token };
	auto info = client.download(from,to);
	REQUIRE(not info.empty());
	auto msg = info["error"].get<std::string>();
	REQUIRE(msg == "UnauthorizedError");
}

TEST_CASE("download invalid file with valid token", "[client][download][file][place]") {

	std::string token = "AQAAAAATPnx3AAQXOJS1w4zmPUdrsJNR1FATxEM";
	path from{ "/yandexTest/1/INVALIDtest.docx" };
  string to = "../test/";
	ydclient client{ token };
	auto info = client.download(from,to);
	REQUIRE(not info.empty());
	auto msg = info["error"].get<std::string>();
	REQUIRE(msg == "DiskNotFoundError");
}
