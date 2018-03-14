@extends('app')
@section('content')

    {!! Form::open(['url' => 'add']) !!}

    <div class="row" xmlns="http://www.w3.org/1999/html">
        <div class="col-md-8 col-md-offset-2 form-horizontal">
            <h3>Add a Class</h3>
            </br></br>

            <div class="form-group {{ ($errors->has('class_code')) ? 'has-error' : '' }}">
                <div class="col-sm-2">
                    {!! Form::label('class_code', 'Class Code*') !!}
                </div>
                <div class="col-sm-5">
                    {!! Form::text('class_code', null, ['class'=>'form-control']) !!}
                    {{ ($errors->has('class_code') ? $errors->first('class_code') : '') }}
                </div>
            </div>

            <div class="form-group {{ ($errors->has('name')) ? 'has-error' : '' }}">
                <div class="col-sm-2">
                    {!! Form::label('name', 'Name*') !!}
                </div>
                <div class="col-sm-5">
                    {!! Form::text('name', null, ['class'=>'form-control']) !!}
                    {{ ($errors->has('name') ? $errors->first('name') : '') }}
                </div>
            </div>

            <div class="form-group {{ ($errors->has('units')) ? 'has-error' : '' }}">
                <div class="col-sm-2">
                    {!! Form::label('units', 'Unit(s)*') !!}
                </div>
                <div class="col-sm-5">
                    {!! Form::text('units', null, ['class'=>'form-control']) !!}
                    {{ ($errors->has('units') ? $errors->first('units') : '') }}
                </div>
            </div>

            <div class="form-group">
                <div class="col-sm-4 col-sm-offset-3">
                    {!! Form::submit('Add Class', ['class'=>'btn btn-primary form-control']) !!}
                </div>
            </div>
        </div>
    </div>
    {!! Form::close() !!}
@stop