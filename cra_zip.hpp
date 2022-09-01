#pragma once

#include <algorithm>
#include <cassert>
#include <span>
#include <utility>

namespace cra
{

namespace dtl
{

class BitReader
{
public:
    explicit BitReader(std::span<const std::uint8_t> s) : s_{s} {}
    std::optional<bool> read_bit()
    {
        assert(i_ < 8U);
        if (s_.empty())
        {
            return std::nullopt;  // all bits consumed
        }
        const bool b = (s_.front() >> i_) & 1U;
        if (i_-- == 0U)
        {
            s_ = s_.last(s_.size() - 1U);
            i_ = 7U;
        }
        return b;
    }
private:
    std::span<const std::uint8_t> s_;
    std::uint8_t i_{7U};  // index of next bit to read in leftmost byte of s_
};

}  // namespace dtl

}  // namespace cra

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;
}
