/*
 *      Copyright (C) 2005-2013 Team XBMC
 *      http://xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#ifndef RAR_EXTRACT_THREAD_H_
#define RAR_EXTRACT_THREAD_H_

#include <xbmc/threads/threads.h>

class Archive;
class CmdExtract;
class CommandData;

class CRarFileExtractThread : public PLATFORM::CThread
{
public:
  CRarFileExtractThread();
  virtual ~CRarFileExtractThread();

  void Start(Archive* pArc, CommandData* pCmd, CmdExtract* pExtract, int iSize);

  virtual void* Process();

  PLATFORM::CEvent hRunning;
  PLATFORM::CEvent hRestart;
  PLATFORM::CEvent hQuit;

protected:
  Archive* m_pArc;
  CommandData* m_pCmd;
  CmdExtract* m_pExtract;
  int m_iSize;
};

#endif