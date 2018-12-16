#ifndef BRIDGES_FINDER_VERTEX_HPP
#define BRIDGES_FINDER_VERTEX_HPP

#include <string>

namespace bridges_finder {

class Vertex
{
public:
    Vertex(const std::string& identity) : identity(identity) {}

    Vertex(const Vertex& vertex) : identity(vertex.identity) {}

    const std::string getIdentity() const {
        return identity;
    }

    Vertex& operator=(const Vertex& vertex) {
        identity = vertex.identity;
        return *this;
    }

    bool operator==(const Vertex& vertex) {
        return identity.compare(vertex.identity) == 0;
    }

protected:
    std::string identity;
};

} // bridges_finder

#endif //BRIDGES_FINDER_VERTEX_HPP
