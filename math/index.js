const math = (function() {
	try {
		return require("./build/Release/math.node");
	} catch(err) {
		return require("./build/Debug/math.node");
	}
})();

console.log("math module:", math.hello());

exports.math = math;

