#include "coordsystem.hpp"
#include "gcd_engine.hpp"

#include "tpcommon/img_img8.hpp"
#include "tdd_helpers.hpp"

#include <catch.hpp>
#include <fakeit.hpp>
#include <future>
#include <vector>
#include <fstream>


using namespace fakeit;
using namespace tp::helpers;
using namespace tp::motor;
using namespace tp::coord;
using namespace tp::gcd;
using namespace tp::img;


TEST_CASE ("GcodeEngine can be used to generate simulated gcode paths","[GcodeEngine][saveToPng]") {
	GcodeEngineConfig gcdwconfiguration = nlohmann::json::parse( R"({
										"config":{
											"GcodeEngine": {
												"simulationFileOutput":"build/unit_simulated_gcode_output.png",
												"toolR":1
											}
										}
									})" );
	GcodeEngine gcdw ( gcdwconfiguration );
	std::ifstream fsgcode("tests/unit_gcd_engine_gcdtest.gcd");
	int ret = gcdw.execGcodeProgram( fsgcode );
	std::cout << "ret = " << ret << std::endl;
	REQUIRE(ret == 0);
}

