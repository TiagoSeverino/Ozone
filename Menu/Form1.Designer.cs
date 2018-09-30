namespace Menu
{
    partial class fMenu
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(fMenu));
            this.btnWH = new System.Windows.Forms.Button();
            this.btnRadar = new System.Windows.Forms.Button();
            this.btnTrigger = new System.Windows.Forms.Button();
            this.btnNoFlash = new System.Windows.Forms.Button();
            this.btnBHOP = new System.Windows.Forms.Button();
            this.btnSave = new System.Windows.Forms.Button();
            this.btnMic = new System.Windows.Forms.Button();
            this.btnRCS = new System.Windows.Forms.Button();
            this.btnAimbot = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btnWH
            // 
            this.btnWH.Location = new System.Drawing.Point(12, 12);
            this.btnWH.Name = "btnWH";
            this.btnWH.Size = new System.Drawing.Size(75, 75);
            this.btnWH.TabIndex = 0;
            this.btnWH.Text = "Wall Hack";
            this.btnWH.UseVisualStyleBackColor = true;
            this.btnWH.Click += new System.EventHandler(this.btnWH_Click);
            // 
            // btnRadar
            // 
            this.btnRadar.Location = new System.Drawing.Point(93, 12);
            this.btnRadar.Name = "btnRadar";
            this.btnRadar.Size = new System.Drawing.Size(75, 75);
            this.btnRadar.TabIndex = 1;
            this.btnRadar.Text = "Radar Hack";
            this.btnRadar.UseVisualStyleBackColor = true;
            this.btnRadar.Click += new System.EventHandler(this.btnRadar_Click);
            // 
            // btnTrigger
            // 
            this.btnTrigger.Location = new System.Drawing.Point(93, 93);
            this.btnTrigger.Name = "btnTrigger";
            this.btnTrigger.Size = new System.Drawing.Size(75, 75);
            this.btnTrigger.TabIndex = 2;
            this.btnTrigger.Text = "TriggerBot";
            this.btnTrigger.UseVisualStyleBackColor = true;
            this.btnTrigger.Click += new System.EventHandler(this.btnTrigger_Click);
            // 
            // btnNoFlash
            // 
            this.btnNoFlash.Location = new System.Drawing.Point(12, 93);
            this.btnNoFlash.Name = "btnNoFlash";
            this.btnNoFlash.Size = new System.Drawing.Size(75, 75);
            this.btnNoFlash.TabIndex = 3;
            this.btnNoFlash.Text = "NoFlash";
            this.btnNoFlash.UseVisualStyleBackColor = true;
            this.btnNoFlash.Click += new System.EventHandler(this.btnNoFlash_Click);
            // 
            // btnBHOP
            // 
            this.btnBHOP.Location = new System.Drawing.Point(174, 12);
            this.btnBHOP.Name = "btnBHOP";
            this.btnBHOP.Size = new System.Drawing.Size(75, 75);
            this.btnBHOP.TabIndex = 4;
            this.btnBHOP.Text = "BHOP";
            this.btnBHOP.UseVisualStyleBackColor = true;
            this.btnBHOP.Click += new System.EventHandler(this.btnBHOP_Click);
            // 
            // btnSave
            // 
            this.btnSave.Location = new System.Drawing.Point(174, 174);
            this.btnSave.Name = "btnSave";
            this.btnSave.Size = new System.Drawing.Size(75, 75);
            this.btnSave.TabIndex = 5;
            this.btnSave.Text = "Save";
            this.btnSave.UseVisualStyleBackColor = true;
            this.btnSave.Click += new System.EventHandler(this.btnSave_Click);
            // 
            // btnMic
            // 
            this.btnMic.Location = new System.Drawing.Point(93, 174);
            this.btnMic.Name = "btnMic";
            this.btnMic.Size = new System.Drawing.Size(75, 75);
            this.btnMic.TabIndex = 6;
            this.btnMic.Text = "Misc";
            this.btnMic.UseVisualStyleBackColor = true;
            this.btnMic.Click += new System.EventHandler(this.btnMic_Click);
            // 
            // btnRCS
            // 
            this.btnRCS.Location = new System.Drawing.Point(174, 93);
            this.btnRCS.Name = "btnRCS";
            this.btnRCS.Size = new System.Drawing.Size(75, 75);
            this.btnRCS.TabIndex = 7;
            this.btnRCS.Text = "No Recoil";
            this.btnRCS.UseVisualStyleBackColor = true;
            this.btnRCS.Click += new System.EventHandler(this.btnRCS_Click);
            // 
            // btnAimbot
            // 
            this.btnAimbot.Location = new System.Drawing.Point(12, 174);
            this.btnAimbot.Name = "btnAimbot";
            this.btnAimbot.Size = new System.Drawing.Size(75, 75);
            this.btnAimbot.TabIndex = 8;
            this.btnAimbot.Text = "Aimbot";
            this.btnAimbot.UseVisualStyleBackColor = true;
            this.btnAimbot.Click += new System.EventHandler(this.btnAimbot_Click);
            // 
            // fMenu
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(261, 258);
            this.Controls.Add(this.btnAimbot);
            this.Controls.Add(this.btnRCS);
            this.Controls.Add(this.btnMic);
            this.Controls.Add(this.btnSave);
            this.Controls.Add(this.btnBHOP);
            this.Controls.Add(this.btnNoFlash);
            this.Controls.Add(this.btnTrigger);
            this.Controls.Add(this.btnRadar);
            this.Controls.Add(this.btnWH);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "fMenu";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "D0minator.xyz";
            this.Load += new System.EventHandler(this.fMenu_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnWH;
        private System.Windows.Forms.Button btnRadar;
        private System.Windows.Forms.Button btnTrigger;
        private System.Windows.Forms.Button btnNoFlash;
        private System.Windows.Forms.Button btnBHOP;
        private System.Windows.Forms.Button btnSave;
        private System.Windows.Forms.Button btnMic;
        private System.Windows.Forms.Button btnRCS;
        private System.Windows.Forms.Button btnAimbot;
    }
}

