#pragma once

#include <MIDI_Interfaces/MIDI_Interface.hpp>
#include <gmock-wrapper.h>

class EmptyParser : public CS::MIDI_Parser {
  public:
    static EmptyParser &getInstance() {
        static EmptyParser instance;
        return instance;
    }
    CS::SysExMessage getSysExMessage() const { return {nullptr, 0, 0}; }
};

class MockMIDI_Interface : public CS::MIDI_Interface {
  public:
    MOCK_METHOD(CS::MIDIReadEvent, read, ());
    MOCK_METHOD(void, sendImpl, (uint8_t, uint8_t, uint8_t, uint8_t),
                (override));
    MOCK_METHOD(void, sendImpl, (uint8_t, uint8_t, uint8_t), (override));
    MOCK_METHOD(void, sendImpl, (const uint8_t *, size_t, uint8_t), (override));
    MOCK_METHOD(void, sendImpl, (uint8_t, uint8_t), (override));
    MOCK_METHOD(void, handleStall, (), (override));
    void update() override {}
};
