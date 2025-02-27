//
// HTTPServer.h
//
// $Id: //poco/1.3/Net/include/Poco/Net/HTTPServer.h#1 $
//
// Library: Net
// Package: HTTPServer
// Module:  HTTPServer
//
// Definition of the HTTPServer class.
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


#ifndef Net_HTTPServer_INCLUDED
#define Net_HTTPServer_INCLUDED


#include "Poco/Net/Net.h"
#include "Poco/Net/TCPServer.h"


namespace Poco {
namespace Net {


class HTTPRequestHandlerFactory;
class HTTPServerParams;


class Net_API HTTPServer: public TCPServer
	/// A subclass of TCPServer that implements a
	/// full-featured multithreaded HTTP server.
	///
	/// A HTTPRequestHandlerFactory must be supplied.
	/// The ServerSocket must be bound and in listening state.
	///
	/// To configure various aspects of the server, a HTTPServerParams
	/// object can be passed to the constructor.
	///
	/// The server supports:
	///   - HTTP/1.0 and HTTP/1.1
	///   - automatic handling of persistent connections.
	///   - automatic decoding/encoding of request/response message bodies
	///     using chunked transfer encoding.
	///
	/// Please see the TCPServer class for information about
	/// connection and thread handling.
	///
	/// See RFC 2616 <http://www.faqs.org/rfcs/rfc2616.html> for more
	/// information about the HTTP protocol.
{
public:
	HTTPServer(HTTPRequestHandlerFactory* pFactory, const ServerSocket& socket, HTTPServerParams* pParams);
		/// Creates the HTTPServer, using the given ServerSocket.
		///
		/// The server takes ownership of the HTTPRequstHandlerFactory
		/// and deletes it when it's no longer needed.
		///
		/// The server also takes ownership of the HTTPServerParams object.
		///
		/// News threads are taken from the default thread pool.

	HTTPServer(HTTPRequestHandlerFactory* pFactory, Poco::ThreadPool& threadPool, const ServerSocket& socket, HTTPServerParams* pParams);
		/// Creates the HTTPServer, using the given ServerSocket.
		///
		/// The server takes ownership of the HTTPRequstHandlerFactory
		/// and deletes it when it's no longer needed.
		///
		/// The server also takes ownership of the HTTPServerParams object.
		///
		/// News threads are taken from the given thread pool.

	~HTTPServer();
		/// Destroys the HTTPServer and its HTTPRequestHandlerFactory.
};


} } // namespace Poco::Net


#endif // Net_HTTPServer_INCLUDED
