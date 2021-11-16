using System;
using System.Collections;
using System.Collections.Generic;
using System.Threading;
using System.Net;
using UnityEngine;
using UnityEngine.UI;
using System.Net.Sockets;
using System.Text;

public class SendSomeData : MonoBehaviour
{
    public TcpListener server;

    //Default host and port
    string host = "127.0.0.1";
    int portTest2 = 52053;
    float test2fromServer;
    public float sendtest2 = 0;       //the value we need to send

    Thread tcpListenerThread;

    // Use this for initialization
    public void Start()
    {
        tcpListenerThread = new Thread(() => ListenForMessages());
        tcpListenerThread.Start();
    }

    public void Update()
    {
        //displayRate();
    }

    public void ListenForMessages()
    {

        try
        {
            // Set the TcpListener on port 13000.
            IPAddress localAddr = IPAddress.Parse(host);

            // TcpListener server = new TcpListener(port);
            server = new TcpListener(localAddr, portTest2);
            //serverS = new TcpListener(localAddr, portStart);

            // Start listening for client requests.
            server.Start();
            
            // Buffer for reading data
            Byte[] bytes = new Byte[1024];      //The byte array containing the sequence of bytes to decode.
            String data = null;

            // Enter the listening loop.
            while (true)
            {
                // Perform a blocking call to accept requests.
                // You could also user server.AcceptSocket() here.
                using (TcpClient client = server.AcceptTcpClient())
                {

                    data = null;
                    // Get a stream object for reading and writing
                    NetworkStream stream = client.GetStream();
                   
                    int i;      //The number of bytes to decode
                    
                    // Loop to receive all the data sent by the client.
                    while ((i = stream.Read(bytes, 0, bytes.Length)) != 0)
                    {
                        //Convert the data to be sent to string
                        data = String.Format("{0:F4}", sendtest2);
                        
                        //Endcode data to be sent to Rhapsody                            
                        byte[] msg = System.Text.Encoding.ASCII.GetBytes(data);

                        // Send back a response.
                        stream.Write(msg, 0, msg.Length);
                    }
                    // Shutdown and end connection
                    client.Close();
                }


            }
        }
        catch (SocketException e)
        {
            Debug.LogError(String.Format("SocketException: {0}", e));
        }
        finally
        {
            // Stop listening for new clients.
            server.Stop();
        }
    }
}
