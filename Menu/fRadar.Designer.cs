﻿namespace Menu
{
    partial class fRadar
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(fRadar));
            this.ckDefault = new System.Windows.Forms.CheckBox();
            this.cbKey = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // ckDefault
            // 
            this.ckDefault.AutoSize = true;
            this.ckDefault.CheckAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.ckDefault.Location = new System.Drawing.Point(12, 12);
            this.ckDefault.Name = "ckDefault";
            this.ckDefault.Size = new System.Drawing.Size(102, 17);
            this.ckDefault.TabIndex = 0;
            this.ckDefault.Text = "Default (On/Off)";
            this.ckDefault.UseVisualStyleBackColor = true;
            // 
            // cbKey
            // 
            this.cbKey.FormattingEnabled = true;
            this.cbKey.Location = new System.Drawing.Point(79, 35);
            this.cbKey.Name = "cbKey";
            this.cbKey.Size = new System.Drawing.Size(121, 21);
            this.cbKey.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 38);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(61, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "Toggle Key";
            // 
            // fWH
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(216, 73);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.cbKey);
            this.Controls.Add(this.ckDefault);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "fRadar";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "D0minator.xyz | Radar Hack";
            this.Load += new System.EventHandler(this.fRadar_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.CheckBox ckDefault;
        private System.Windows.Forms.ComboBox cbKey;
        private System.Windows.Forms.Label label1;
    }
}