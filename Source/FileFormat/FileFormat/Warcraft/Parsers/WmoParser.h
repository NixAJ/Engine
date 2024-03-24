#pragma once
#include <Base/Types.h>

#include <robinhood/robinhood.h>

class Bytebuffer;
struct FileChunkHeader;

namespace Wmo
{
    struct Layout;

    class Parser
    {
    public:
        enum class ParseType
        {
            Root,
            Group
        };

        Parser() { }

        bool TryParse(const ParseType parseType, std::shared_ptr<Bytebuffer>& buffer, Wmo::Layout& out);

    private:
        bool ParseBufferOrderIndependent(ParseType parseType, std::shared_ptr<Bytebuffer>& buffer, Wmo::Layout& out);

    private:
        // Shared Chunks
        static bool ReadMVER(const ParseType parseType, const FileChunkHeader& header, std::shared_ptr<Bytebuffer>& buffer, Wmo::Layout& wmo);

    private:
        // Root Chunks
        static bool ReadMOHD(const ParseType parseType, const FileChunkHeader& header, std::shared_ptr<Bytebuffer>& buffer, Wmo::Layout& wmo);
        static bool ReadMOMT(const ParseType parseType, const FileChunkHeader& header, std::shared_ptr<Bytebuffer>& buffer, Wmo::Layout& wmo);
        static bool ReadMOGN(const ParseType parseType, const FileChunkHeader& header, std::shared_ptr<Bytebuffer>& buffer, Wmo::Layout& wmo);
        static bool ReadMOGI(const ParseType parseType, const FileChunkHeader& header, std::shared_ptr<Bytebuffer>& buffer, Wmo::Layout& wmo);
        static bool ReadMOSI(const ParseType parseType, const FileChunkHeader& header, std::shared_ptr<Bytebuffer>& buffer, Wmo::Layout& wmo);
        static bool ReadMOPV(const ParseType parseType, const FileChunkHeader& header, std::shared_ptr<Bytebuffer>& buffer, Wmo::Layout& wmo);
        static bool ReadMOPT(const ParseType parseType, const FileChunkHeader& header, std::shared_ptr<Bytebuffer>& buffer, Wmo::Layout& wmo);
        static bool ReadMOPR(const ParseType parseType, const FileChunkHeader& header, std::shared_ptr<Bytebuffer>& buffer, Wmo::Layout& wmo);
        static bool ReadMOLT(const ParseType parseType, const FileChunkHeader& header, std::shared_ptr<Bytebuffer>& buffer, Wmo::Layout& wmo);
        static bool ReadMODS(const ParseType parseType, const FileChunkHeader& header, std::shared_ptr<Bytebuffer>& buffer, Wmo::Layout& wmo);
        static bool ReadMODI(const ParseType parseType, const FileChunkHeader& header, std::shared_ptr<Bytebuffer>& buffer, Wmo::Layout& wmo);
        static bool ReadMODD(const ParseType parseType, const FileChunkHeader& header, std::shared_ptr<Bytebuffer>& buffer, Wmo::Layout& wmo);
        static bool ReadGFID(const ParseType parseType, const FileChunkHeader& header, std::shared_ptr<Bytebuffer>& buffer, Wmo::Layout& wmo);

    private:
        // Group Chunks
        static bool ReadMOGP(const ParseType parseType, const FileChunkHeader& header, std::shared_ptr<Bytebuffer>& buffer, Wmo::Layout& wmo);
        static bool ReadMOPY(const ParseType parseType, const FileChunkHeader& header, std::shared_ptr<Bytebuffer>& buffer, Wmo::Layout& wmo);
        static bool ReadMOVI(const ParseType parseType, const FileChunkHeader& header, std::shared_ptr<Bytebuffer>& buffer, Wmo::Layout& wmo);
        static bool ReadMOVT(const ParseType parseType, const FileChunkHeader& header, std::shared_ptr<Bytebuffer>& buffer, Wmo::Layout& wmo);
        static bool ReadMONR(const ParseType parseType, const FileChunkHeader& header, std::shared_ptr<Bytebuffer>& buffer, Wmo::Layout& wmo);
        static bool ReadMOTV(const ParseType parseType, const FileChunkHeader& header, std::shared_ptr<Bytebuffer>& buffer, Wmo::Layout& wmo);
        static bool ReadMOBA(const ParseType parseType, const FileChunkHeader& header, std::shared_ptr<Bytebuffer>& buffer, Wmo::Layout& wmo);
        static bool ReadMOCV(const ParseType parseType, const FileChunkHeader& header, std::shared_ptr<Bytebuffer>& buffer, Wmo::Layout& wmo);

    private:
        static robin_hood::unordered_map<u32, std::function<bool(const Parser::ParseType parseType, const FileChunkHeader&, std::shared_ptr<Bytebuffer>&, Wmo::Layout& out)>> _wmoFileChunkToFunction;
    };
}