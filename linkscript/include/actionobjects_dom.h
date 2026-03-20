#ifndef ACTIONOBJECTS_DOM
#define ACTIONOBJECTS_DOM

#include <string>

#include <emscripten.h>

EM_JS(void, js_create_button, (const char* text, const char* id, const char* onclick), {
    const btn = document.createElement("button");

    btn.innerText = UTF8ToString(text);
    btn.id = UTF8ToString(id);

    // Optional click handler (string-based for now)
    const handler = UTF8ToString(onclick);
    if (handler.length > 0) {
        btn.onclick = function() {
            console.log("[AFX CLICK]", handler);
        };
    }

    document.body.appendChild(btn);
});

#endif