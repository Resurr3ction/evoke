#pragma once

#include <boost/filesystem.hpp>
#include <string>
#include <unordered_map>
#include <unordered_set>

struct Component;

struct File {
    File(const boost::filesystem::path& path, Component& component)
    : path(path)
    , component(component)
    , hasExternalInclude(false)
    , hasInclude(false)
    {
    }
    void AddIncludeStmt(bool withPointyBrackets, const std::string& filename) {
        rawIncludes.insert(std::make_pair(filename, withPointyBrackets));
    }
    boost::filesystem::path path;
    std::unordered_map<std::string, bool> rawIncludes;
    std::unordered_set<File *> dependencies;
    std::unordered_set<std::string> includePaths;
    Component &component;
    bool hasExternalInclude;
    bool hasInclude;
};

