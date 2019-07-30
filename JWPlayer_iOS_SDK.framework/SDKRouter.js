var SDKRouter = {

    pause() {
        window.webkit.messageHandlers.pause.postMessage("");
    },

    play() {
        window.webkit.messageHandlers.play.postMessage("");
    },

    stop() {
        window.webkit.messageHandlers.stop.postMessage("");
    },

    seek(position) {
        window.webkit.messageHandlers.seek.postMessage(position);
    },

    fastSeek(position) {
        window.webkit.messageHandlers.fastSeek.postMessage(position);
    },

    load(item, providerId) {
        /*
         Per MDN (https://developer.mozilla.org/en-US/docs/Web/API/Window/postMessage):
         message is serialized using the structured clone algorithm,
         meaning that error and function objects cannot be duplicated.
         When parsing captions, the xhr object is added to the track. The xhr object contains function properties.
         Stringifying and then parsing back to JSON allows us to strip out functions.
         Since this conversion could result in undefined or throw an error in the case of syntax errors,
         we fallback to a basic item containing just the file.
         */
        var itemWithoutFunctions;
        var itemFallback = { file: item.file };
        try {
            itemWithoutFunctions = JSON.parse(JSON.stringify(item)) || itemFallback;
        } catch(e) {
            itemWithoutFunctions = itemFallback;
        }
        window.webkit.messageHandlers.load.postMessage({
                                                       item: itemWithoutFunctions,
                                                       providerId: providerId
                                                       });
    },

    setCurrentAudioTrack(index) {
        window.webkit.messageHandlers.setCurrentAudioTrack.postMessage(index);
    },

    setCurrentEmbeddedCaption(index) {
        window.webkit.messageHandlers.setCurrentEmbeddedCaption.postMessage(index);
    },

    controlBarIsVisible(isVisible) {
        window.webkit.messageHandlers.controlBarIsVisible.postMessage(isVisible);
    },

    setPlaybackRate(playbackRate) {
        window.webkit.messageHandlers.setPlaybackRate.postMessage(playbackRate);
    },
    
    parseLocalFile(url, uniqueKey) {
        window.webkit.messageHandlers.parseLocalFile.postMessage({
                                                                 url: url,
                                                                 uniqueKey: uniqueKey
                                                                 });
    }
};
