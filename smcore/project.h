//******************************************************************************
// Copyright (C) 1999 Jim Wanner and the SourceMonitor team.
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//******************************************************************************

#pragma once

#include <ctime>
#include <fstream>
#include <iostream>

#include "error.h"
#include "optionflags.h"
#include "smstring.h"
#include "subdirectorymode.h"

namespace smos
{
    namespace smcore
    {
        class Project
        {
        public:
            /**
             * @brief Construct a new Project object
             */
            Project(void);

            /**
             * @brief Destroy the Project object
             */
            ~Project(void);

            /**
             * @brief Get indicator of whether to use subdirectories
             *
             * @return SubdirectoryMode Kind of subdirectory usage
             */
            smos::smcore::SubdirectoryMode getIncludeSubdirectories(void);

            /**
             * @brief Get all option flags
             *
             * @return int
             */
            int GetOptionFlags(void) const;

            /**
             * @brief Get the Project Name
             *
             * @return smos::smcore::SMString
             */
            smos::smcore::SMString getProjectName(void) const;

            /**
             * @brief Get the path to the code for analysis
             *
             * @return smos::smcore::SMString
             */
            smos::smcore::SMString getSourcePath(void) const;

            /**
             * @brief Set flag to ignore header/footer
             *
             * @param ignore
             */
            void IgnoreHeaderFooter(int ignore);

            /**
             * @brief Get flag to ignore header/footer
             *
             * @return int
             */
            int IgnoreHeaderFooter(void) const;

            /**
             * @brief Get flag if file list is from XML file
             *
             * @return bool
             */
            bool IsFileListFromXmlFile(void) const;

            /**
             * @brief Load project data
             *
             * @param filename Name of project file
             * @param project Pointer to project object
             *
             * @return smos::smcore::Error::ErrorCode
             */
            static smos::smcore::Error::ErrorCode loadProject(const smos::smcore::SMString &filename, Project &project);

            /**
             * @brief Save project data
             *
             * @param filename Name of project file
             * @param project Pointer to project object
             * @param force Force saving in case project file already exist
             *
             * @return smos::smcore::Error::ErrorCode
             */
            static smos::smcore::Error::ErrorCode saveProject(const smos::smcore::SMString &filename, Project &project, bool force = false);

            /**
             * @brief Set flag if file list is from XML file
             *
             * @param isFileListFromXmlFile
             */
            void SetFileListFromXmlFile(bool isFileListFromXmlFile);

            /**
             * @brief Enable/disable usage of subdirectories
             *
             * @param usage SubdirectoryMode Kind of subdirectory usage
             */
            void setIncludeSubdirectories(SubdirectoryMode usage);

            /**
             * @brief Set all option flags
             *
             * @param options
             */
            void SetOptionFlags(int options);

            /**
             * @brief Set the Project Name
             *
             * @param projectName
             */
            void setProjectName(smos::smcore::SMString projectName);

            /**
             * @brief Set the path to the code for analysis
             *
             * @param directory Path to source code
             */
            void setSourcePath(smos::smcore::SMString directory);

            /**
             * @brief Set flag using of blank lines
             *
             * @param ignoreBlankLines
             */
            void UseIgnoreBlankLines(bool ignoreBlankLines);

            /**
             * @brief Get flag using of blank lines
             *
             * @return bool
             */
            bool UseIgnoreBlankLines(void) const;

            /**
             * @brief Set flag for modified complexity
             *
             * @param useModifiedComplexity
             */
            void UseModifiedComplexity(bool useModifiedComplexity);

            /**
             * @brief Get flag for modified complexity
             *
             * @return bool
             */
            bool UseModifiedComplexity(void) const;

            /**
             * @brief Enable writing to stream
             *
             * @param os Outputstream to write to
             * @param obj Project object to write to stream
             *
             * @return std::ostream&
             */
            friend std::ostream &operator<<(std::ostream &os, const Project &obj);

            /**
             * @brief Enable reading from stream
             *
             * @param is Inputstream to read from
             * @param obj Project object to read from stream
             *
             * @return std::istream&
             */
            friend std::istream &operator>>(std::istream &is, Project &obj);

        private:
            /**
             * @brief Number of current class version for versioning
             */
            uint16_t m_ClassVersion;

            /**
             * @brief Project setting: Include subdirectories yes/no
             */
            smos::smcore::SubdirectoryMode m_includeSubdirectories;

            /**
             * @brief Some options - need more inspection for knowing kind of options and what they tweak
             */
            int m_OptionFlags;

            /**
             * @brief Location of project file
             */
            smos::smcore::SMString m_ProjectFileDirectory;

            /**
             * @brief Filename of project file
             */
            smos::smcore::SMString m_ProjectFileName;

            /**
             * @brief Name of project
             */
            smos::smcore::SMString m_ProjectName;

            /**
             * @brief Location of project source code
             */
            smos::smcore::SMString m_sDirectory;

            /**
             * @brief Reference to language object
             */
            // SMLanguage *m_poLanguageExemplar; // exemplar is used to build all project language objects
            /**
             * @brief Version object
             */
            // SMVersion m_oVersion;             // version of SourceMonitor that created this project
            /**
             * @brief List of project checkpoints, ordered list?
             *
             */
            // CheckpointList m_oCheckpoints;    // list of checkponts in the project

            // transient (non-persisted) members
            // CStringArray m_saFilesXmlPathNames;   // Xml files that holds the paths to all project files
            // CStringArray m_saXmlFileXPathFilters; // XPath specifications that define locations of project files in xml file
            // CString m_sBaseDirectory;             // base directory for source files with relative references resolved
            // CString m_sRootDirectory;             // base directory as read from project file - may be relative
            // CString m_sXmlFileDirectory;          // directory where the current XML file is located
            // CStringArray m_saSubDirectories;      // list of (relative) sub-directories
            // SubdirectoryMode m_eSubdirectoryMode;
            // CStringArray m_saIncludeExtensionList;  // list of file extensions to search for
            // CStringArray m_saExcludeExtensionList;  // list of file extensions to exclude (subset of the include list)
            // CWordArray m_waExcludeExtensionLengths; // lengths of the extensions in the exclude list
            // CheckpointList m_oDeletedCheckpoints;   // list of deleted checkponts
            // bool m_fNewFileFormat;                  // true if project is saved in the new binary format instead of the MFC Serialize format
            // bool m_fProcessingXMLTest;              // controls display of XML extraction errors only when user is testing an XML specification
        };
    }
}
