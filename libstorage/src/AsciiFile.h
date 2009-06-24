// -*- C++ -*-
// Maintainer: fehr@suse.de

#ifndef _AsciiFile_h
#define _AsciiFile_h

#include <vector>
#include <list>

using std::string;

namespace storage
{

class Regex;

#define DBG(x)

///////////////////////////////////////////////////////////////////
//
//	CLASS NAME : AsciiFile
//
//	DESCRIPTION :
//
class AsciiFile
    {
    public:
	AsciiFile( bool CreateBackup_bv=false, 
		   const char* BackupExt_Cv=".orig" );
	AsciiFile( const string& Name_Cv, bool CreateBackup_bv=false, 
		   const char* BackupExt_Cv=".orig" );
	AsciiFile( const char* Name_Cv, bool CreateBackup_bv=false, 
		   const char* BackupExt_Cv=".orig" );
	~AsciiFile();
	bool insertFile( AsciiFile& File_Cv, unsigned int BeforeLine_iv=0 );
	bool appendFile( AsciiFile& File_Cv );
	bool insertFile( const string& Name_Cv, unsigned int BeforeLine_iv=0 );
	bool appendFile( const string& Name_Cv );
	bool loadFile( const string& Name_Cv );
	bool updateFile();
	bool saveToFile( const string& Name_Cv );
	void append( const string& Line_Cv );
	void append( const std::list<string>& Lines_Cv );
	void insert( unsigned int Before_iv, const string& Line_Cv );
	void remove( unsigned int Start_iv, unsigned int Cnt_iv );
	void replace( unsigned int Start_iv, unsigned int Cnt_iv,
		      const string& Line_Cv );
	void replace( unsigned int Start_iv, unsigned int Cnt_iv,
		      const std::list<string>& Line_Cv );
	const string& operator []( unsigned int Index_iv ) const;
	string& operator []( unsigned int Index_iv );
	int find( unsigned int Start_iv, const string& Pat_Cv ) const;
	int find( unsigned int Start_iv, Regex& Pat_Cv ) const;
	unsigned numLines() const; 
	const string& fileName() const;
	unsigned differentLine( const AsciiFile& File_Cv ) const;
	bool removeIfEmpty();

    protected:
	bool appendFile( const string&  Name_Cv, std::vector<string>& Lines_Cr );
	bool appendFile( AsciiFile& File_Cv, std::vector<string>& Lines_Cr );

	bool BackupCreated_b;
	string BackupExtension_C;
	std::vector<string> Lines_C;
	string Name_C;
    };

}

#endif