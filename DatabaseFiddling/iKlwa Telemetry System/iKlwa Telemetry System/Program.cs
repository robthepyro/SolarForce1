﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.IO.Ports;
using System.Drawing;
using System.Windows.Forms;

namespace iKlwa_Telemetry_System
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
    }

    class CommsManager
    {
        private SerialPort port;

        #region accessors for port setup
        public int baud_rate
        {
            get
            {
                return port.BaudRate;
            }
            set
            {
                port.BaudRate = value;
            }
        }//possible need for error checking code

        public enum Parities : int { Odd, Even, NoParity };
        public int parity
        {
            set
            {
                switch (value)
                {
                    case (int)Parities.Odd:
                        port.Parity = Parity.Odd;
                        break;

                    case (int)Parities.Even:
                        port.Parity = Parity.Even;
                        break;

                    case (int)Parities.NoParity:
                        port.Parity = Parity.None;
                        break;
                    default:
                        port.Parity = Parity.None;
                        throw new ArgumentException("Only Odd, Even or No Parity Supported");
                }
            }
        }

        public string name
        {
            get
            { return port.PortName; }
            set
            {
                port.PortName = value;
            }
        }

        public int data_bits
        {
            set
            {
                if (value < 1 || value > 9)
                {
                    port.DataBits = 8;
                    throw new ArgumentException("Minimum of 1 and Maximum of 9 stop bits permitted");
                }
                else
                    port.DataBits = value;
            }
        }

        public int stop_bits
        {
            set
            {
                if (value == 1)
                    port.StopBits = StopBits.One;
                else if (value == 2)
                    port.StopBits = StopBits.Two;
                else
                {
                    port.StopBits = StopBits.One;
                    throw new ArgumentException("Only one or two stop bits supported");
                }
            }
        }

        public int interrupt_bytes_threshold
        {
            get { return port.ReceivedBytesThreshold; }
            set
            {
                if (value < 1)
                {
                    port.ReceivedBytesThreshold = 1;
                    throw new ArgumentException("Threshold should be at least 1 byte");
                }
                else port.ReceivedBytesThreshold = value;
            }
        }

        public int read_timeout
        {
            set
            {
                if (value < 1)
                {
                    port.ReadTimeout = 100;
                    throw new ArgumentException("There should be finite read timeout.");
                }
                else port.ReadTimeout = value;
            }
        }
        #endregion

        #region basic reading and writing functions
        public int readByte()
        {
            int val = port.ReadByte();
            return val;
        }

        public byte[] readBytes()
        {
            int values = port.BytesToRead;
            byte[] buffer = new byte[values];
            port.Read(buffer, 0, values);
            return buffer;
        }

        public string readText()
        {
            int values = port.BytesToRead;
            char[] buffer = new char[values];
            port.Read(buffer, 0, values);
            return new String(buffer);
        }

        public void writeBytes(byte[] values)
        {
            port.Write(values, 0, values.Length);
        }

        public void writeByte(byte val)
        {
            byte[] data = {val};
            port.Write(data,0,1);
        }

        public void writeText(string msg)
        {
            port.Write(msg);
        }

        #endregion

        private SerialDataReceivedEventHandler current_DREH;
        public delegate void general_data_received_handler(object o, SerialDataReceivedEventArgs e);
        public void set_data_received_event_handler(general_data_received_handler data_received_handler)
        {
            if (!current_DREH.Equals(null))
                port.DataReceived -= current_DREH;
            current_DREH = new SerialDataReceivedEventHandler(data_received_handler);
            port.DataReceived += current_DREH;
        }

        public CommsManager()
        {
            port = new SerialPort();
            defaultInit();
        }

        protected void defaultInit()
        {
            try
            {
                baud_rate = 4800;
                name = "COM9";
                data_bits = 8;
                stop_bits = 2;
                parity = (int)Parities.Odd;
                interrupt_bytes_threshold = 1;
            }
            catch (Exception e)
            { MessageBox.Show(e.Message); }
        }

        public void OpenPort()
        {
            if (port.IsOpen)
                port.Close();
            try
            {
                port.Open();
            }
            catch (Exception e)
            {
                MessageBox.Show(e.Message);
            }
        }

        protected void Clear()
        {
            port.DiscardInBuffer();
        }
    }

    class iKlwaComms:CommsManager
    {
        private byte pingReq = 0x3f;
        private byte ACK = 0x55;

        public iKlwaComms() { }

        public bool checkForPing()
        {
            int readVal = this.readByte();
            bool pingFound = (readVal==pingReq);
            if (pingFound)
                this.writeByte(ACK);
            return pingFound;
        }
    }
}