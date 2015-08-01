(function() {
	module.exports = {
		penetrate: function(windowTitle) {
			var addon = require('./bindings-fork')('./penetrate.node');
			return addon.penetrate(windowTitle);
		}
	}
})();