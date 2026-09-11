#ifndef VIDEO_H
#define VIDEO_H

#include "media_resource.h"
#include <memory>

class Video {
private:
    std::shared_ptr<MediaResource> resource;

public:
    explicit Video(std::shared_ptr<MediaResource> res);

    // Inlined accessors per Rule #6
    const std::string& getIdentity() const { return resource->getIdentity(); }
    const std::string& getSource() const { return resource->getSourcePath(); }
    double getDuration() const { return resource->getDuration(); }

    bool isLinked() const { return resource && resource.use_count() > 1; }

    // Lifecycle and domain modifications
    void separate();
    void cut(double startTime, double endTime);
};

#endif // VIDEO_H
