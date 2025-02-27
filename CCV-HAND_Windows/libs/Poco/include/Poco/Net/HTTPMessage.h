//
// HTTPMessage.h
//
// $Id: //poco/1.3/Net/include/Poco/Net/HTTPMessage.h#1 $
//
// Library: Net
// Package: HTTP
// Module:  HTTPMessage
//
// Definition of the HTTPMessage class.
//
// Copyright (c) 2005-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef Net_HTTPMessage_INCLUDED
#define Net_HTTPMessage_INCLUDED


#include "Poco/Net/Net.h"
#include "Poco/Net/MessageHeader.h"


namespace Poco {
namespace Net {


class MediaType;


class Net_API HTTPMessage: public MessageHeader
	/// The base class for HTTPRequest and HTTPResponse.
	///
	/// Defines the common properties of all HTTP messages.
	/// These are version, content length, content type
	/// and transfer encoding.
{
public:
	void setVersion(const std::string& version);
		/// Sets the HTTP version for this message.
		
	const std::string& getVersion() const;
		/// Returns the HTTP version for this message.
		
	void setContentLength(int length);
		/// Sets the Content-Length header.
		///
		/// If length is UNKNOWN_CONTENT_LENGTH, removes
		/// the Content-Length header.
		
	int getContentLength() const;
		/// Returns the content length for this message,
		/// which may be UNKNOWN_CONTENT_LENGTH if
		/// no Content-Length header is present.

	void setTransferEncoding(const std::string& transferEncoding);
		/// Sets the transfer encoding for this message.
		///
		/// The value should be either IDENTITY_TRANSFER_CODING
		/// or CHUNKED_TRANSFER_CODING.

	const std::string& getTransferEncoding() const;
		/// Returns the transfer encoding used for this
		/// message.
		///
		/// Normally, this is the value of the Transfer-Encoding
		/// header field. If no such field is present,
		/// returns IDENTITY_TRANSFER_CODING.
		
	void setChunkedTransferEncoding(bool flag);
		/// If flag is true, sets the Transfer-Encoding header to
		/// chunked. Otherwise, removes the Transfer-Encoding
		/// header.
		
	bool getChunkedTransferEncoding() const;
		/// Returns true if the Transfer-Encoding header is set
		/// and its value is chunked.
		
	void setContentType(const std::string& mediaType);
		/// Sets the content type for this message.
		///
		/// Specify NO_CONTENT_TYPE to remove the
		/// Content-Type header.
		
	void setContentType(const MediaType& mediaType);	
		/// Sets the content type for this message.
		
	const std::string& getContentType() const;
		/// Returns the content type for this message.
		///
		/// If no Content-Type header is present, 
		/// returns UNKNOWN_CONTENT_TYPE.	

	void setKeepAlive(bool keepAlive);
		/// Sets the value of the Connection header field.
		///
		/// The value is set to "Keep-Alive" if keepAlive is
		/// true, or to "Close" otherwise.

	bool getKeepAlive() const;
		/// Returns true if
		///   * the message has a Connection header field and its value is "Keep-Alive"
		///   * the message is a HTTP/1.1 message and not Connection header is set
		/// Returns false otherwise.

	static const std::string HTTP_1_0;
	static const std::string HTTP_1_1;

	static const std::string IDENTITY_TRANSFER_ENCODING;
	static const std::string CHUNKED_TRANSFER_ENCODING;

	static const int         UNKNOWN_CONTENT_LENGTH;
	static const std::string UNKNOWN_CONTENT_TYPE;
	
	static const std::string CONTENT_LENGTH;
	static const std::string CONTENT_TYPE;
	static const std::string TRANSFER_ENCODING;
	static const std::string CONNECTION;
	
	static const std::string CONNECTION_KEEP_ALIVE;
	static const std::string CONNECTION_CLOSE;

protected:
	HTTPMessage();
		/// Creates the HTTPMessage with version HTTP/1.0.

	HTTPMessage(const std::string& version);
		/// Creates the HTTPMessage and sets
		/// the version.

	virtual ~HTTPMessage();
		/// Destroys the HTTPMessage.
	
private:
	HTTPMessage(const HTTPMessage&);
	HTTPMessage& operator = (const HTTPMessage&);
	
	std::string _version;
};


//
// inlines
//
inline const std::string& HTTPMessage::getVersion() const
{
	return _version;
}


} } // namespace Poco::Net


#endif // Net_HTTPMessage_INCLUDED
