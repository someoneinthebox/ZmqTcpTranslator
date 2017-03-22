# ZmqTcpTranslator
ZMQ-TCP/IP translator Windows service for those who can't use ZMQ library for some reasons.

# Introduction

ZmqTcpTranslator a Windows service that catch ZMQ-publisher's packets and send them to TCP/IP server by simple socket.

# System requirements

There is no special requirements for this service. There are two conditions: ZMQ Publisher and working server, listening needed port for recieve data.

# Installation

For installation the service run *cmd* (**as Administrator**), and run tcprectranslator.exe with –i parameter.

# Start the service

To start the service - just start it from Windows Service manager. If you want to run service with specific parameters, you can find them in <a href="https://github.com/someoneinthebox/ZmqTcpTranslator/wiki" target="_blank"><b>wiki</b></a>.

# Where are the logs?

By default, logs location is *system32* folder (for x64 - *SYSWOW64*).
