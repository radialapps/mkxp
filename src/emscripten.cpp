#include "emscripten.hpp"

#ifdef __EMSCRIPTEN__

EM_JS(void, load_file_async_js, (const char* fullPathC, int bitmap), {
	Asyncify.handleSleep(function(wakeUp) {
    	window.loadFileAsync(UTF8ToString(fullPathC), bitmap, wakeUp);
	});
});

EM_JS(void, save_file_async_js, (const char* fullPathC), {
	if (window.saveFile) window.saveFile(UTF8ToString(fullPathC));
});

EM_JS(int, file_is_cached, (const char* fullPathC), {
	const fullPath = UTF8ToString(fullPathC);
	const mappingKey = getMappingKey(fullPath);
	return window.fileAsyncCache.hasOwnProperty(mappingKey) ? 1 : 0;
});

#endif

