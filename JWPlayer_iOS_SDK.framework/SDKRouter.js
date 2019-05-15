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

    preloadTitle(title) {
        window.webkit.messageHandlers.preloadTitle.postMessage(title);
    },

    preloadImage(image) {
        window.webkit.messageHandlers.preloadImage.postMessage(image);
    },

    load(providerId, file, time, payload, preload) {
        window.webkit.messageHandlers.load.postMessage({
                                                       providerId: providerId,
                                                       file: file,
                                                       time: time,
                                                       payload: payload,
                                                       preload: preload

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
    }
};
