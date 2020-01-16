<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.num1 = New System.Windows.Forms.TextBox
        Me.num2 = New System.Windows.Forms.TextBox
        Me.result = New System.Windows.Forms.Label
        Me.Label2 = New System.Windows.Forms.Label
        Me.Label3 = New System.Windows.Forms.Label
        Me.Label4 = New System.Windows.Forms.Label
        Me.sumButton = New System.Windows.Forms.Button
        Me.diffButton = New System.Windows.Forms.Button
        Me.SuspendLayout()
        '
        'num1
        '
        Me.num1.Location = New System.Drawing.Point(29, 67)
        Me.num1.Name = "num1"
        Me.num1.Size = New System.Drawing.Size(100, 20)
        Me.num1.TabIndex = 0
        '
        'num2
        '
        Me.num2.Location = New System.Drawing.Point(159, 67)
        Me.num2.Name = "num2"
        Me.num2.Size = New System.Drawing.Size(100, 20)
        Me.num2.TabIndex = 1
        '
        'result
        '
        Me.result.AutoSize = True
        Me.result.Location = New System.Drawing.Point(100, 211)
        Me.result.Name = "result"
        Me.result.Size = New System.Drawing.Size(0, 13)
        Me.result.TabIndex = 2
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(29, 48)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(71, 13)
        Me.Label2.TabIndex = 3
        Me.Label2.Text = "Enter Value 1"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Location = New System.Drawing.Point(159, 48)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(71, 13)
        Me.Label3.TabIndex = 4
        Me.Label3.Text = "Enter Value 2"
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Location = New System.Drawing.Point(100, 185)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(53, 13)
        Me.Label4.TabIndex = 5
        Me.Label4.Text = "RESULT:"
        '
        'sumButton
        '
        Me.sumButton.Location = New System.Drawing.Point(54, 125)
        Me.sumButton.Name = "sumButton"
        Me.sumButton.Size = New System.Drawing.Size(75, 23)
        Me.sumButton.TabIndex = 6
        Me.sumButton.Text = "Sum"
        Me.sumButton.UseVisualStyleBackColor = True
        '
        'diffButton
        '
        Me.diffButton.Location = New System.Drawing.Point(159, 125)
        Me.diffButton.Name = "diffButton"
        Me.diffButton.Size = New System.Drawing.Size(75, 23)
        Me.diffButton.TabIndex = 7
        Me.diffButton.Text = "Difference"
        Me.diffButton.UseVisualStyleBackColor = True
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(292, 273)
        Me.Controls.Add(Me.diffButton)
        Me.Controls.Add(Me.sumButton)
        Me.Controls.Add(Me.Label4)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.result)
        Me.Controls.Add(Me.num2)
        Me.Controls.Add(Me.num1)
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents num1 As System.Windows.Forms.TextBox
    Friend WithEvents num2 As System.Windows.Forms.TextBox
    Friend WithEvents result As System.Windows.Forms.Label
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents Label4 As System.Windows.Forms.Label
    Friend WithEvents sumButton As System.Windows.Forms.Button
    Friend WithEvents diffButton As System.Windows.Forms.Button

End Class
