//===-- CommandObjectDisassemble.h ------------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef liblldb_CommandObjectDisassemble_h_
#define liblldb_CommandObjectDisassemble_h_

// C Includes
// C++ Includes
// Other libraries and framework includes
// Project includes
#include "lldb/Interpreter/CommandObject.h"
#include "lldb/Interpreter/Options.h"

namespace lldb_private {

//-------------------------------------------------------------------------
// CommandObjectDisassemble
//-------------------------------------------------------------------------

class CommandObjectDisassemble : public CommandObject
{
public:
    class CommandOptions : public Options
    {
    public:

        CommandOptions (CommandInterpreter &interpreter);

        virtual
        ~CommandOptions ();

        virtual Error
        SetOptionValue (int option_idx, const char *option_arg);

        void
        ResetOptionValues ();

        const OptionDefinition*
        GetDefinitions ();

        const char *
        GetPluginName ()
        {
            if (plugin_name.empty())
                return NULL;
            return plugin_name.c_str();
        }
        

        bool show_mixed; // Show mixed source/assembly
        bool show_bytes;
        uint32_t num_lines_context;
        uint32_t num_instructions;
        bool raw;
        std::string func_name;
        lldb::addr_t start_addr;
        lldb::addr_t end_addr;
        bool at_pc;
        bool frame_line;
        std::string plugin_name;
        ArchSpec arch;
        static OptionDefinition g_option_table[];
    };

    CommandObjectDisassemble (CommandInterpreter &interpreter);

    virtual
    ~CommandObjectDisassemble ();

    virtual
    Options *
    GetOptions ()
    {
        return &m_options;
    }

    virtual bool
    Execute (Args& command,
             CommandReturnObject &result);

protected:
    CommandOptions m_options;

};

} // namespace lldb_private

#endif  // liblldb_CommandObjectDisassemble_h_
